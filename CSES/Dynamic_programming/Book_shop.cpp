#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M, Score = 0;
  cin >> N >> M;
  vector<pair<int, int>> V(N);
  vector<LL> dp(M + 1), prev_dp(M + 1);
  for(auto&e : V)
    cin >> e.first;
  for(auto&e : V)
    cin >> e.second;
  for(int i = 0; i < N; i++){
    for(int w = M - V[i].first; w >= 0; w--){
      dp[w] = max(prev_dp[w], prev_dp[w + V[i].first] + V[i].second);
      Score = max(Score, dp[w]);
    }
    prev_dp = dp;
  }
  cout << Score << '\n';
}
