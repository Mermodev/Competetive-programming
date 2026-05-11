#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M;
  cin >> N >> M;
  vector<int> V(N);
  map<int, int> Pos;
  for(int i = 0; i < N; i++){
    cin >> V[i];
    if(Pos[M - V[i]] != 0){
      cout << i + 1 << ' ' << Pos[M - V[i]] << '\n';
      return 0;
    }
    Pos[V[i]] = i + 1;
  }
  cout << "IMPOSSIBLE\n";
}
