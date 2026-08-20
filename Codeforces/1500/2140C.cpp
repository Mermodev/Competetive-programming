#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<int> V(N);
    for(auto&e : V)
      cin >> e;
    long long Ans = 0;
    for(int i = 0; i < N; i++)
      Ans += (i % 2) ? -V[i] : V[i];
    long long Init = Ans;
    for(int i = 0; i < N; i++)
      Ans = max(Ans, Init + i - (i % 2));
    long long MinEven = LLONG_MAX / 2, MinOdd = LLONG_MAX / 2;
    for(int i = 0; i < N; i++){
      if(i % 2){
        Ans = max(Init + i + V[i] * 2 - MinEven, Ans);
        MinOdd = min(MinOdd, i - 2ll * V[i]);
      }
      else{
        Ans = max(Init + i - 2 * V[i] - MinOdd, Ans);
        MinEven = min(MinEven, i + 2ll * V[i]);
      }
    }
    cout << Ans << '\n';
  }
}
