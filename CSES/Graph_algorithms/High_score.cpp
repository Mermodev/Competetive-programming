#include<bits/stdc++.h>
using namespace std;

struct Edge{
  long long from, where, cost;
  bool Added;
};

void dfs(int Curr, vector<vector<Edge>>&G, vector<bool>&Vis, vector<Edge>&Adj, int&Count){
  Vis[Curr] = true;
  Count++;
  for(auto&e : G[Curr]){
    if(!e.Added){
      Adj.push_back({e.where, e.from, e.cost, true});
      e.Added = true;
    }
    if(!Vis[e.where])
      dfs(e.where, G, Vis, Adj, Count);
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, a, b, c;
  cin >> N >> M;
  vector<vector<Edge>> G(N + 1);
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    G[b].push_back({b, a, -c, false});
  }
  vector<long long> Dist(N + 1, 1e18);
  vector<bool> Vis(N + 1, 0);
  vector<Edge> Adj;
  N = 0;
  dfs(G.size() - 1, G, Vis, Adj, N);
  Dist[1] = 0;
  for(int Phase = 0; Phase <= N; Phase++)
    for(auto&e : Adj)
      if(Dist[e.from] != 1e18 && Dist[e.from] + e.cost < Dist[e.where]){
        if(Phase == N){
          cout << "-1\n";
          return 0;
        }
        Dist[e.where] = Dist[e.from] + e.cost;
      }
  cout << -Dist[G.size() - 1] << '\n';
}
