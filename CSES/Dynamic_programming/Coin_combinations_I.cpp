#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M;
  cin >> N >> M;
  vector<LL> V(N), dp(M + 1);
  for(auto&e : V)
    cin >> e;
  dp[0] = 1;
  for(int i = 1; i <= M; i++)
    for(int x = 0; x < N; x++)
      if(i - V[x] >= 0)
        dp[i] = (dp[i] + dp[i - V[x]]) % 1000000007;
  cout << dp[M] << '\n';
}
