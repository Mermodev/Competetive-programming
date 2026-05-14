#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M;
  cin >> N >> M;
  vector<int> V(N), dp(M + 1);
  for(auto&e : V)
    cin >> e;
  dp[0] = 1;
  for(int i = 0; i < N; i++)
    for(int x = V[i]; x <= M; x++)
      dp[x] = (dp[x] + dp[x - V[i]]) % 1000000007;
  cout << dp[M] << '\n';
}
