#include<bits/stdc++.h>
using namespace std;

int SolveRow(int RowNumber, vector<vector<bool>> BlockedPositions){
  if(RowNumber == 8)
    return 1;
  int Output = 0;
  for(int i = 0; i < 8; i++){
    vector<vector<bool>> BlockedPositionsCopy = BlockedPositions;
    if(BlockedPositions[RowNumber][i])
      continue;
    else{
      int y = RowNumber, x = i;
      while(y < 7 && x > 0){
        y++; x--;
        BlockedPositionsCopy[y][x] = true;
      }
      y = RowNumber;
      while(y < 7){
        y++;
        BlockedPositionsCopy[y][i] = true;
      }
      y = RowNumber; x = i;
      while(y < 7 && x < 7){
        y++; x++;
        BlockedPositionsCopy[y][x] = true;
      }
      Output += SolveRow(RowNumber + 1, BlockedPositionsCopy);
    }
  }
  return Output;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  vector<vector<bool>> BlockedPositions(8, vector<bool>(8, false));
  string S;
  for(int i = 0; i < 8; i++){
    cin >> S;
    for(int x = 0; x < 8; x++)
      if(S[x] == '*') 
        BlockedPositions[i][x] = true;
  }
  cout << SolveRow(0, BlockedPositions);
}
