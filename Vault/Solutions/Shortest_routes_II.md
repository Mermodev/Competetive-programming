---
tags:
  - graph
  - floyd_warshall
---

# Shortest_routes_II.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Edge{
  long long where, cost;
};

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, Q, a, b, c;
  cin >> N >> M >> Q;
  vector<vector<Edge>> G(N + 1);
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  vector<vector<long long>> Dist(N + 1, vector<long long>(N + 1, 1e17));
  for(int i = 0; i <= N; i++)
    for(auto&e : G[i])
      Dist[i][e.where] = min(Dist[i][e.where], e.cost);
  for(int i = 0; i <= N; i++)
    Dist[i][i] = 0;
  for(int k = 1; k <= N; k++)
    for(int i = 1; i <= N; i++)
      for(int j = 1; j <= N; j++)
        if(Dist[i][j] > Dist[i][k] + Dist[k][j])
          Dist[i][j] = Dist[i][k] + Dist[k][j];
  while(Q--){
    cin >> a >> b;
    if(Dist[a][b] == 1e17)
      cout << "-1\n";
    else 
      cout << Dist[a][b] << '\n';
  }
}
```
