#include<bits/stdc++.h>
using namespace std;

int main(){
  int Q;
  cin >> Q;
  while(Q--){
    long long A, N;
    cin >> A >> N;
    vector<int> Nums(N);
    for(auto&e : Nums)
      cin >> e;
    sort(Nums.begin(), Nums.end());
    Nums.erase(unique(Nums.begin(), Nums.end()), Nums.end());
    string S = to_string(A);
    int L = S.size();
    int MinAvail = Nums.front(), MaxAvail = Nums.back();
    int M = 0;
    while(M < L && binary_search(Nums.begin(), Nums.end(), S[M] - '0'))
      M++;
    if(M == L){
      cout << 0 << '\n';
      continue;
    }
    long long Best = -1;
    for(int i = 0; i <= M; i++){
      int Curr = S[i] - '0';
      int Up = -1, Down = -1;
      for(auto e : Nums){
        if(e > Curr){ Up = e; break; }
      }
      for(auto e : Nums){
        if(e < Curr) Down = e;
      }
      if(Up != -1){
        string T = S.substr(0, i) + char('0' + Up) + string(L - i - 1, char('0' + MinAvail));
        long long Val = stoll(T);
        long long D = Val - A;
        if(Best == -1 || D < Best) Best = D;
      }
      if(Down != -1){
        string T = S.substr(0, i) + char('0' + Down) + string(L - i - 1, char('0' + MaxAvail));
        long long Val = stoll(T);
        long long D = A - Val;
        if(Best == -1 || D < Best) Best = D;
      }
    }
    cout << Best << '\n';
  }
}
