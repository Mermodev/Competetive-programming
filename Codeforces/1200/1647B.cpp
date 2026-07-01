#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, M;
    string S;
    cin >> N >> M;
    bool Continue = true;
    vector<vector<int>> Board(N + 2, vector<int>(M + 2, 0));
    vector<vector<int>> Vis(N + 2, vector<int> (M + 2, 0));
    for(int i = 0; i < N; i++){
      cin >> S;
      for(int j = 0; j < M; j++){
        if(S[j] == '0')
          Board[i + 1][j + 1] = 0;
        else 
          Board[i + 1][j + 1] = 1;
      }
    }
    for(int y = 1; y <= N &&  Continue; y++){
      for(int x = 1; x <= M && Continue; x++){
        if(Board[y][x] == 1 && !Vis[y][x]){
          int Xcount = 0, YCount = 0;
          while(Board[y][x + Xcount] == 1 && Continue){
            if(Board[y - 1][x + Xcount] == 1 && !Vis[y - 1][x + Xcount])
              Continue = false;
            Xcount++;
          }
          while(Board[y + YCount][x] == 1 && Board[y + YCount][x + Xcount - 1] == 1 && Continue){
            if((Board[y + YCount][x - 1] == 1 && !Vis[y + YCount][x - 1]) || (Board[y + YCount][x + Xcount] == 1 && !Vis[y + YCount][x + Xcount]))
              Continue = false;
            YCount++;
          }
          Xcount = 0;
          while(Board[y + YCount - 1][x + Xcount] == 1 && Continue){
            if(Board[y + YCount][x + Xcount] == 1 && ! Vis[y + YCount][x + Xcount])
              Continue = false;
            Xcount++;
          }
          for(int nY = y; nY < y + YCount && Continue; nY++)
            for(int nX = x; nX < x + Xcount && Continue; nX++){
              if(Board[nY][nX] == 0)
                Continue = false;
              Vis[nY][nX] = 1;
            }
        }
      }
    }
    if(Continue)
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
}
