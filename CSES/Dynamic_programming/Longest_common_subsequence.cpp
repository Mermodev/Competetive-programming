#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M;
  cin >> N >> M;
  vector<LL> V1(N), V2(M);
  for(auto&e : V1)
    cin >> e;
  for(auto&e : V2)
    cin >> e;
  vector<vector<LL>> dp(N + 1, vector<LL>(M + 1));
  for(int y = 1; y <= N; y++)
    for(int x = 1; x <= M; x++)
      if(V1[y - 1] == V2[x - 1])
        dp[y][x] = dp[y - 1][x - 1] + 1;
      else
        dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]);
  vector<LL> ans;
  int y = N, x = M;
  while(y && x){
    if(V1[y - 1] == V2[x - 1]){
      ans.push_back(V1[y - 1]);
      y--;
      x--;
    }
    else if(dp[y - 1][x] > dp[y][x - 1])
      y--;
    else
      x--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(auto&e : ans)
    cout << e << ' ';
}
