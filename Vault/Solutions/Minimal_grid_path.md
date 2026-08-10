---
tags:
  - dp
  - queue
---

# Minimal_grid_path.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  vector<string> Grid(N);
  for(auto&e : Grid)
    cin >> e;
  vector<vector<bool>> Vis(N, vector<bool>(N, false));
  queue<pair<LL, LL>> Q, Next;
  string Ans;
  Ans += Grid[0][0];
  Q.push({0, 0});
  Vis[0][0] = true;
  while(Ans.size() < 2 * N - 1){
    char best = 'Z' + 1;
    while(!Q.empty()){
      auto [y, x] = Q.front();
      Q.pop();
      if(y + 1 < N){
        if(Grid[y + 1][x] <= best && !Vis[y + 1][x]){
          if(Grid[y + 1][x] < best){
            best = Grid[y + 1][x];
            while(!Next.empty())
              Next.pop();
          }
          Vis[y + 1][x] = true;
          Next.push({y + 1, x});
        }
      }
      if(x + 1 < N){
        if(Grid[y][x + 1] <= best && !Vis[y][x + 1]){
          if(Grid[y][x + 1] < best){
            best = Grid[y][x + 1];
            while(!Next.empty())
              Next.pop();
          }
          Vis[y][x + 1] = true;
          Next.push({y, x + 1});
        }
      }
    }
    Ans += best;
    swap(Q, Next);
  }
  cout << Ans << '\n';
}
```
