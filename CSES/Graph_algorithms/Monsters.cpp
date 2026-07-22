#include<bits/stdc++.h>
using namespace std;

struct Tile{
  int x, y;
  char state;
};

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  queue<Tile> Q;
  vector<string> Board(N);
  vector<char> dD = {'D', 'R', 'U', 'L'};
  vector<int> dX = {0, 1, 0, -1}, dY = {1, 0, -1, 0};
  vector<vector<char>> Direction(N, vector<char>(M, 'N'));
  for(auto&e : Board)
    cin >> e;
  for(int y = 0; y < N; y++)
    for(int x = 0; x < M; x++)
      if(Board[y][x] == 'M')
        Q.push({x, y, 'M'});
  int Sx = -1, Sy = -1;
  for(int y = 0; y < N; y++)
    for(int x = 0; x < M; x++)
      if(Board[y][x] == 'A'){
        Sx = x, Sy = y;
        Q.push({x, y, 'P'});
      }
  if(Sx == 0 || Sy == 0 || Sx == M - 1 || Sy == N - 1){
    cout << "YES\n" << 0 << '\n' << '\n';
    return 0;
  }
  string Ans;
  while(!Q.empty()){
    Tile Main = Q.front();
    Q.pop();
    if(Board[Main.y][Main.x] == '#')
      continue;
    Board[Main.y][Main.x] = (Main.state == 'P') ? '&' : '#';
    for(int i = 0; i < 4; i++){
      Tile Curr = {Main.x + dX[i], Main.y + dY[i], Main.state};
      if(Curr.x < 0 || Curr.y < 0 || Curr.x == M || Curr.y == N)
        continue;
      if(Curr.state == 'M'){
        if(Board[Curr.y][Curr.x] != '#'){
          Q.push({Curr.x, Curr.y, Curr.state});
          Board[Curr.y][Curr.x] = '%';
        }
      }
      if(Curr.state == 'P'){
        if(Board[Curr.y][Curr.x] == '.'){
          Direction[Curr.y][Curr.x] = dD[i];
          if(Curr.x == 0 || Curr.y == 0 || Curr.x == M - 1 || Curr.y == N - 1){
            Tile Back = Curr;
            while(Direction[Back.y][Back.x] != 'N'){
              char d = Direction[Back.y][Back.x];
              Ans.push_back(d);
              if(d == 'D') Back.y--;
              else if(d == 'U') Back.y++;
              else if(d == 'R') Back.x--;
              else if(d == 'L') Back.x++;
            }
            reverse(Ans.begin(), Ans.end());
            cout << "YES\n" << Ans.size() << '\n' << Ans << '\n';
            return 0;
          }
          Q.push({Curr.x, Curr.y, Curr.state});
        }
      }
    }
  }
  cout << "NO\n";
}
