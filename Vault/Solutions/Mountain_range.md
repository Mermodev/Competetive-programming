---
tags:
  - dp
  - counting
  - stack
---

# Mountain_range.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  vector<LL> V(N);
  for(auto&e : V)
    cin >> e;
  vector<pair<LL, LL>> ToLeft(N, {-1, -1}), ToRight(N, {-1, -1});
  vector<LL> Parent(N);
  stack<pair<LL, LL>> S;
  S.push({INT_MAX, -1});
  for(int i = 0; i < N; i++){
    while(V[i] >= S.top().first)
      S.pop();
    ToLeft[i] = S.top();
    S.push({V[i], i});
  }
  while(!S.empty())
    S.pop();
  S.push({INT_MAX, -1});
  for(int i = N - 1; i >= 0; i--){
    while(V[i] >= S.top().first)
      S.pop();
    ToRight[i] = S.top();
    S.push({V[i], i});
  }
  for(int i = 0; i < N; i++){
    if(ToLeft[i].first < ToRight[i].first)
      Parent[i] = ToLeft[i].second;
    else
      Parent[i] = ToRight[i].second;
  }
  vector<LL> Depth(N, 0);
  LL maxDepth = 0;
  for(int i = 0; i < N; i++) {
    if(Depth[i]) 
      continue;
    vector<LL> Path;
    LL curr = i;
    while (curr != -1 && Depth[curr] == 0) {
      Path.push_back(curr);
      curr = Parent[curr];
    }
    int d = (curr == -1 ? 1 : Depth[curr] + 1);
    for(LL j = (LL)Path.size() - 1; j >= 0; j--) {
      Depth[Path[j]] = d++;
      maxDepth = max(maxDepth, Depth[Path[j]]);
    }
  }
  cout << maxDepth << '\n';
}
```
