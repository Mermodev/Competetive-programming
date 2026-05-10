#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  vector<string> V(N);
  for(auto&e : V)
    cin >> e;
  for(int y = 0; y < N; y++){
    for(int x = 0; x < M; x++){
      if(V[y][x] == 'A' || V[y][x] == 'B'){
        if((x + y) % 2)
          cout << 'C';
        else 
          cout << 'D';
      }
      else{
        if((x + y) % 2)
          cout << 'A';
        else 
          cout << 'B';
      }
    }
    cout << '\n';
  }
}
