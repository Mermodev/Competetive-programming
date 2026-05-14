#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<string> B(N);
  for(auto&e : B)
    cin >> e;
  vector<vector<LL>> dp(N + 1, vector<LL>(N + 1));
  dp[0][1] = 1;
  for(int y = 1; y <= N; y++)
    for(int x = 1; x <= N; x++)
      dp[y][x] = ((dp[y - 1][x] + dp[y][x - 1]) * (B[y - 1][x - 1] == '.')) % 1000000007;
  cout << dp[N][N] << '\n';
} 
