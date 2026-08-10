---
tags:
  - dfs
  - graph
---

# Round_trip_II.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;

bool dfs(int Curr, vector<int>&State, vector<int>&Parent, vector<vector<int>>&G){
  State[Curr] = 1;
  for(auto&e : G[Curr]){
    if(State[e] == 1){
      vector<int> Cycle;
      int Temp = Curr;
      while(Temp != e){
        Cycle.push_back(Temp);
        Temp = Parent[Temp];
      }
      Cycle.push_back(e);
      reverse(Cycle.begin(), Cycle.end());
      cout << Cycle.size() + 1 << '\n';
      for(auto&x : Cycle)
        cout << x << ' ';
      cout << Cycle[0] << '\n';
      return true;
    }
    if(State[e] == 0){
      Parent[e] = Curr;
      if(dfs(e, State, Parent, G))
        return true;
    }
  }
  State[Curr] = 2;
  return false;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N + 1);
  for(int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
  }
  vector<int> State(N + 1, 0), Parent(N + 1, -1);
  for(int Curr = 1; Curr <= N; Curr++){
    if(State[Curr] != 0)
      continue;
    if(dfs(Curr, State, Parent, G))
      return 0;
  }
  cout << "IMPOSSIBLE\n";
}
```
