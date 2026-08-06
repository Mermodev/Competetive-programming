#include <bits/stdc++.h>
using namespace std;
const long long NEG_INF = LLONG_MIN / 2;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    string S;
    cin >> S;
    long long Z = 0, O = 0;
    int R = 0;
    int FirstIdx0 = -1, LastIdx0 = -1, FirstIdx1 = -1, LastIdx1 = -1;
    for(int i = 0; i < N; i++){
      if(S[i] == '0') Z++; else O++;
      if(i == 0 || S[i] != S[i-1]){
        R++;
        if(S[i] == '0'){
          if(FirstIdx0 == -1) FirstIdx0 = R;
          LastIdx0 = R;
        } else {
          if(FirstIdx1 == -1) FirstIdx1 = R;
          LastIdx1 = R;
        }
      }
    }
    long long MaxK0    = R - (R % 2);
    long long MaxKPlus1  = (FirstIdx0 == -1) ? NEG_INF : (LastIdx0 - FirstIdx0 + 1);
    long long MaxKMinus1 = (FirstIdx1 == -1) ? NEG_INF : (LastIdx1 - FirstIdx1 + 1);
    long long Diff = Z - O;
    long long Best = NEG_INF;
    if(llabs(Diff - 0) <= 1) Best = max(Best, MaxK0);
    if(llabs(Diff - 1) <= 1) Best = max(Best, MaxKPlus1);
    if(llabs(Diff + 1) <= 1) Best = max(Best, MaxKMinus1);
    if(Best <= NEG_INF / 2)
      cout << -1 << '\n';
    else
      cout << (N - Best) << '\n';
  }
}
