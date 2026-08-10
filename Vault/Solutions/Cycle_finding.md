---
tags:
  - graph
  - bellman_ford
---

# Cycle_finding.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;

struct Edge{
  long long from, where, cost;
};

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, a, b, c;
  cin >> N >> M;
  vector<Edge> Adj;
  for(int i = 0; i < M; i++){
    cin >> a >> b >> c;
    Adj.push_back({a, b, c});
  }
  vector<long long> Dist(N + 1, 0);
  vector<int> Parent(N + 1, 0), Ans(0);
  Dist[1] = 0;
  for(int Phase = 0; Phase <= N; Phase++)
    for(auto&e : Adj)
      if(Dist[e.from] != 1e18 && Dist[e.from] + e.cost < Dist[e.where]){
        Parent[e.where] = e.from;
        Dist[e.where] = Dist[e.from] + e.cost;
        if(Phase == N){
          int Curr = Parent[e.where];
          for(int i = 0; i < N; i++)
            Curr = Parent[Curr];
          Ans.emplace_back(Curr);
          Curr = Parent[Curr];
          while(Curr != Ans[0]){
            Ans.emplace_back(Curr);
            Curr = Parent[Curr];
          }
          reverse(Ans.begin(), Ans.end());
          Ans.emplace_back(Ans[0]);
          cout << "YES\n";
          for(auto&e : Ans)
            cout << e << ' ';
          cout << '\n';
          return 0;
        }
      }
  if(Ans.size() == 0)
    cout << "NO\n";
}
```
