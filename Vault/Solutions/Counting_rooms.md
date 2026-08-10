---
tags:
  - graph
  - bfs
  - queue
---

# Counting_rooms.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  vector<string> Board(N);
  for(auto&e : Board)
    cin >> e;
  int Count = 0;
  for(int y = 0; y < N; y++)
    for(int x = 0; x < M; x++)
      if(Board[y][x] == '.'){
        Count++;
        queue<pair<int, int>> Q;
        vector<int> dX = {0, 1, 0, -1}, dY = {1, 0, -1, 0};
        Q.push(make_pair(x, y));
        Board[y][x] = '#';
        while(!Q.empty()){
          for(int i = 0; i < 4; i++)
            if(Q.front().first + dX[i] >= 0 && Q.front().first + dX[i] < M && Q.front().second + dY[i] >= 0 && Q.front().second + dY[i] < N)
              if(Board[Q.front().second + dY[i]][Q.front().first + dX[i]] == '.'){
                Board[Q.front().second + dY[i]][Q.front().first + dX[i]] = '#';
                Q.push(make_pair(Q.front().first + dX[i], Q.front().second + dY[i]));
              }
          Q.pop();
        }
      }
  cout << Count << '\n';
}
```
