#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M;
  cin >> N >> M;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  vector<LL> dp(M + 1, INT_MAX);
  dp[0] = 0;
  for(int i = 1; i <= M; i++)
    for(int x = 0; x < N; x++)
      if(i - V[x] >= 0)
        dp[i] = min(dp[i], dp[i - V[x]] + 1ll);
  cout << ((dp[M] != INT_MAX) ? dp[M] : -1) << '\n';
}
