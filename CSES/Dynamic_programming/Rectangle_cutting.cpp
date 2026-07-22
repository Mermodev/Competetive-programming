#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M;
  cin >> N >> M;
  vector<vector<LL>> dp(N + 1, vector<LL>(M + 1, INT_MAX));
  for(int i = 1; i <= min(N, M); i++)
    dp[i][i] = 0;
  for(int y = 1; y <= N; y++){
    for(int x = 1; x <= M; x++){
      if(y == x)
        continue;
      for(int i = 1; i < y; i++)
        dp[y][x] = min(dp[y][x], dp[y - i][x] + dp[i][x] + 1);
      for(int i = 1; i < x; i++)
        dp[y][x] = min(dp[y][x], dp[y][x - i] + dp[y][i] + 1);
    }
  }
  cout << dp[N][M] << '\n';
}
