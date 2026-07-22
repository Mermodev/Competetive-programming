#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  vector<string> Board(N);
  vector<vector<char>> Direction(N, vector<char>(M, 'N'));
  for(auto&e : Board)
    cin >> e;
  queue<pair<int, int>> Q;
  vector<int> dX = {0, 1, 0, -1}, dY = {1, 0, -1, 0};
  vector<char> dD = {'D', 'R', 'U', 'L'};
  for(int y = 0; y < N && Q.empty(); y++)
    for(int x = 0; x < M && Q.empty(); x++)
      if(Board[y][x] == 'A'){
        Q.push(make_pair(x, y));
        Board[y][x] = '#';
      }
  string Out;
  while(!Q.empty()){
    auto Main = Q.front();
    Q.pop();
    for(int i = 0; i < 4; i++){
      auto Curr = make_pair(Main.first + dX[i], Main.second + dY[i]);
      if(Curr.second >= 0 && Curr.second < N && Curr.first >= 0 &&  Curr.first < M && Board[Curr.second][Curr.first] != '#'){
        Direction[Curr.second][Curr.first] = dD[i];
        if(Board[Curr.second][Curr.first] == 'B'){
          while(Direction[Curr.second][Curr.first] != 'N'){
            Out.push_back(Direction[Curr.second][Curr.first]);
            if(Out[Out.size() - 1] == 'D')
              Curr.second--;
            if(Out[Out.size() - 1] == 'R')
              Curr.first--;
            if(Out[Out.size() - 1] == 'U')
              Curr.second++;
            if(Out[Out.size() - 1] == 'L')
              Curr.first++;
          }
          reverse(Out.begin(), Out.end());
          cout << "YES\n" << Out.size() << '\n' << Out << '\n';
          return 0;
        }
        Board[Curr.second][Curr.first] = '#';
        Q.push(Curr);
      }
    }
  }
  if(Out.size() == 0)
    cout << "NO\n";
}
