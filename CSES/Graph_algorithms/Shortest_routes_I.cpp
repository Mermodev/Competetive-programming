#include<bits/stdc++.h>
using namespace std;

struct Edge{
  long long where, cost;
  bool operator<(const Edge&other) const{
    return this->cost < other.cost;
  }
};

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, a, b, c;
  cin >> N >> M;
  vector<vector<Edge>> G(N);
  vector<long long> Dist(N, LLONG_MAX);
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    G[--a].push_back({--b, c});
  }
  priority_queue<Edge> pQ;
  Dist[0] = 0;
  pQ.push({0, 0});
  while(!pQ.empty()){
    Edge Curr = pQ.top();
    pQ.pop();
    if(-Curr.cost > Dist[Curr.where])
      continue;
    for(auto&e : G[Curr.where])
      if(Dist[e.where] > -Curr.cost + e.cost){
        Dist[e.where] = -Curr.cost + e.cost;
        pQ.push({e.where, -Dist[e.where]});
      }
  }
  for(auto&e : Dist)
    cout << e << ' ';
  cout << '\n';
}
