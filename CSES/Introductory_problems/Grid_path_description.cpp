#include<bits/stdc++.h>
using namespace std;

#define LL long long 

bool Vis[7][7];
string Desc;

inline int dfs(int X, int Y, int Depth){
  if(Depth == 48)
    return (X == 0 && Y == 6);
  if(X == 0 && Y == 6)
    return 0;
  if ((X == 0 || Vis[Y][X - 1]) &&
      (X == 6 || Vis[Y][X + 1]) &&
      (Y > 0 && !Vis[Y - 1][X]) &&
      (Y < 6 && !Vis[Y + 1][X]))
    return 0;

  if ((Y == 0 || Vis[Y - 1][X]) &&
      (Y == 6 || Vis[Y + 1][X]) &&
      (X > 0 && !Vis[Y][X - 1]) &&
      (X < 6 && !Vis[Y][X + 1]))
    return 0;
  Vis[Y][X] = true;
  int Sum = 0;
  if(X > 0 && (Desc[Depth] == '?' || Desc[Depth] == 'L') && !Vis[Y][X-1])
    Sum += dfs(X - 1, Y, Depth + 1);
  if(Y > 0 && (Desc[Depth] == '?' || Desc[Depth] == 'U') && !Vis[Y-1][X])
    Sum += dfs(X, Y - 1, Depth + 1);
  if(X < 6 && (Desc[Depth] == '?' || Desc[Depth] == 'R') && !Vis[Y][X+1])
    Sum += dfs(X + 1, Y, Depth + 1);
  if(Y < 6 && (Desc[Depth] == '?' || Desc[Depth] == 'D') && !Vis[Y+1][X])
    Sum += dfs(X, Y + 1, Depth + 1);
  Vis[Y][X] = false;
  return Sum;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> Desc;
  cout << dfs(0, 0, 0) << '\n';
}
