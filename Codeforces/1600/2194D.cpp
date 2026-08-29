#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    long long N, M, Count = 0;
    cin >> N >> M;
    vector<vector<int>> Board(N, vector<int>(M));
    for(auto&Row : Board)
      for(auto&e : Row){
        cin >> e;
        Count += e;
      }
    cout << (Count / 2) * ((Count + 1) / 2) << '\n';
    bool Moved = false;
    Count = Count / 2 + Count % 2;
    for(int Row = 0; Row < N; Row++){
      for(int Column = M - 1; Column >= 0 && !Moved; Column--){
        if(Board[Row][Column])
          Count--;
        if(Count == 0){
          Row++;
          Moved = true;
          for(int Left = 0; Left < Column; Left++)
            cout << "R";
          cout << "D";
          for(int Right = Column; Right < M; Right++)
            cout << "R";
        }
      }
      if(Row < N)
        cout << "D";
    }
    cout << '\n';
  }
}
