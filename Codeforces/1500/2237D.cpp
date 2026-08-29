#include<bits/stdc++.h>
using namespace std;

int main(){
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    string S;
    cin >> S;
    long long Freq[3] = {1, 0, 0};
    int Pm = 0;
    long long Count0 = 0;
    for(int i = 0; i < N; i++){
      int V = (S[i] == '0') ? 1 : 2;
      Pm = (Pm + V) % 3;
      Count0 += Freq[Pm];
      Freq[Pm]++;
    }
    long long Total = (long long)N * (N + 1) / 2;
    long long Ans = Total - Count0;

    long long FalsePos = 0;
    int ChainLen = 1;
    for(int i = 1; i < N; i++){
      if(S[i] != S[i - 1]){
        ChainLen++;
      } else {
        long long L = ChainLen;
        long long J = (L - 1) / 2;
        FalsePos += J * (L - J - 1);
        ChainLen = 1;
      }
    }
    long long L = ChainLen;
    long long J = (L - 1) / 2;
    FalsePos += J * (L - J - 1);

    Ans -= FalsePos;
    cout << Ans << '\n';
  }
}
