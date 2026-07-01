#include<bits/stdc++.h>
using namespace std;

long long dfs(int C, int P, vector<vector<int>>&G, vector<long long>&dp){
  for(auto&e : G[C])
    if(e != P) 
      dp[C] += dfs(e, C, G, dp);
  if(G[C].size() == 1 && P != -1)
    dp[C] = 1;
  return dp[C];
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, a, b;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++){
      cin >> a >> b;
      G[--a].emplace_back(--b);
      G[b].emplace_back(a);
    }
    vector<long long> dp(N, 0);
    dfs(0, -1, G, dp);
    cin >> N;
    while(N--){
      cin >> a >> b;
      cout << (long long)(dp[--a] * dp[--b]) << '\n';
    }
  }
}
