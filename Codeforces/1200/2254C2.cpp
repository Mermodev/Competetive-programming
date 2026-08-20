#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;
    vector<int> EvenA, EvenB, OddA, OddB;
    for(int i = 0; i < N; i++){
      if(i % 2== 0){
        if(A[i] == '1') EvenA.emplace_back(i/2);
        if(B[i] == '1') EvenB.emplace_back(i/2);
      }
      else{
        if(A[i] == '1') OddA.emplace_back(i/2);
        if(B[i] == '1') OddB.emplace_back(i/2);
      }
    }
    if(EvenA.size() != EvenB.size() || OddA.size() != OddB.size()){
      cout << -1 << '\n';
      continue;
    }
    sort(EvenA.begin(), EvenA.end());
    sort(EvenB.begin(), EvenB.end());
    sort(OddA.begin(), OddA.end());
    sort(OddB.begin(), OddB.end());
    long long Ans = 0;
    for(int i = 0; i < EvenA.size(); i++)
      Ans += abs(EvenA[i] - EvenB[i]);
    for(int i = 0; i < OddA.size(); i++)
      Ans += abs(OddA[i] - OddB[i]);
    cout << Ans << '\n';
  }
}
