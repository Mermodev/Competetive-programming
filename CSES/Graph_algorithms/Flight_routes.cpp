#include<bits/stdc++.h>
using namespace std;

struct Edge{
  long long Where, Cost;
  bool operator<(const Edge&other) const{
    return this->Cost < other.Cost;
  }
};

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<Edge>> G(N + 1);
  for(int i = 0; i < M; i++){
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back({v, -w});
  }
  vector<priority_queue<long long>> Distance(N + 1);
  priority_queue<Edge> pQ;
  Distance[1].push(0);
  pQ.push({1, 0});
  while(!pQ.empty()){
    Edge Curr = pQ.top();
    pQ.pop();
    if(Curr.Cost > Distance[Curr.Where].top()) 
      continue;
    for(auto&e : G[Curr.Where]){
      if(Distance[e.Where].size() < K){
        Distance[e.Where].push(-e.Cost - Curr.Cost);
        pQ.push({e.Where, e.Cost + Curr.Cost});
      }
      else if(-e.Cost - Curr.Cost < Distance[e.Where].top()){
        Distance[e.Where].pop();
        Distance[e.Where].push(-e.Cost - Curr.Cost);
        pQ.push({e.Where, e.Cost + Curr.Cost});
      }
    }
  }
  vector<long long> Ans;
  while(!Distance[N].empty()){
    Ans.push_back(Distance[N].top());
    Distance[N].pop();
  }
  reverse(Ans.begin(), Ans.end());
  for(auto&e : Ans)
    cout << e << ' ';
  cout << '\n';
}
