#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ssize(x) (LL)(x.size())

int MexFromTwo(vector<int> V1, vector<int> V2, int Border1, int Border2){
  vector<bool> Seen(Border1 + Border2);
  for(int i = 0; i < Border1; i++)
    if(V1[i] < Border1 + Border2)
      Seen[V1[i]] = true;
  for(int i = 0; i < Border2; i++)
    if(V2[i] < Border1 + Border2)
      Seen[V2[i]] = true;
  int Ans = 0;
  for(;Ans < Border1 + Border2; Ans++){
    if(!Seen[Ans])
      return Ans;
  }
  return Border1 + Border2;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<vector<int>> Rows(N, vector<int>(N));
  vector<vector<int>> Cols(N, vector<int>(N));
  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
      LL Temp = MexFromTwo(Rows[y], Cols[x], x, y);
      Rows[y][x] = Temp;
      Cols[x][y] = Temp;
    }
  }
  for(auto&e : Rows){
    for(auto&g : e)
      cout << g << ' ';
    cout << '\n';
  }
}
