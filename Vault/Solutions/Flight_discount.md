---
tags:
  - graph
  - dijkstra
  - dp
  - priority_queue
---

# Flight_discount.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Edge{
  long long where, cost;
  bool split;
  bool operator<(const Edge&other) const{
    return this->cost > other.cost;
  }
};

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, a, b, c;
  cin >> N >> M;
  vector<vector<Edge>> G(N + 1);
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    G[a].push_back({b, c, false});
    //G[b].push_back({a, c});
  }
  vector<pair<long long, long long>> Dist(N + 1, make_pair(LLONG_MAX, LLONG_MAX));
  priority_queue<Edge> pQ;
  pQ.push({1, 0, 0});
  pQ.push({1, 0, 1});
  while(!pQ.empty()){
    Edge Curr = pQ.top();
    pQ.pop();
    if(Curr.split == 0 && Curr.cost > Dist[Curr.where].first)
      continue;
    if(Curr.split == 1 && Curr.cost > Dist[Curr.where].second)
      continue;
    if(Curr.split == 0)
      Dist[Curr.where].first = Curr.cost;
    if(Curr.split == 1)
      Dist[Curr.where].second = Curr.cost;
    for(auto&e : G[Curr.where]){
      if(Curr.split == false && Dist[e.where].first > Dist[Curr.where].first + e.cost){
        pQ.push({e.where, Dist[Curr.where].first + e.cost, false});
        Dist[e.where].first = Dist[Curr.where].first + e.cost;
      }
      if(Curr.split == false && Dist[e.where].second > Dist[Curr.where].first + e.cost / 2){
        pQ.push({e.where, Dist[Curr.where].first + e.cost / 2, true});
        Dist[e.where].second = Dist[Curr.where].first + e.cost / 2;
      }
      if(Curr.split == true && Dist[e.where].second > Dist[Curr.where].second + e.cost){
        pQ.push({e.where, Dist[Curr.where].second + e.cost, true});
        Dist[e.where].second = Dist[Curr.where].second + e.cost;
      }
    }
  }
  cout << min(Dist[N].first, Dist[N].second) << '\n';
}
```
