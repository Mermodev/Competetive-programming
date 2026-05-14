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
  vector<vector<LL>> dp(N, vector<LL>(M + 2));
  if(V[0] != 0)
    dp[0][V[0]] = 1;
  else 
    for(int i = 1; i <= M; i++)
      dp[0][i] = 1;
  for(int i = 1; i < N; i++)
    for(int x = 1; x <= M; x++){
      dp[i][x] = (dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]) % 1000000007;
      if(V[i] != 0 && V[i] != x)
        dp[i][x] = 0;
    }
  LL Sum = 0;
  for(auto e : dp[N-1])
    Sum = (Sum + e) % 1000000007;
  cout << Sum << '\n';
}
