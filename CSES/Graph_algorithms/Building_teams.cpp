#include<bits/stdc++.h>
using namespace std;

bool dfs(int C, int P, vector<vector<int>>&G, vector<int>&Color){
  for(auto&e : G[C]){
    if(Color[e] == Color[C])
      return false;
    if(e != P && Color[e] == 0){
      Color[e] = (Color[C] == 1) ? 2 : 1;
      if(!dfs(e, C, G, Color))
        return false;
    }
  }
  return true;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, a, b;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    G[--a].emplace_back(--b);
    G[b].emplace_back(a);
  }
  vector<int> Color(N, 0);
  for(int i = 0; i < N; i++)
    if(Color[i] == 0){
      Color[i] = 1;
      if(!dfs(i, -1, G, Color)){
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  for(auto&e : Color)
    cout << e << ' ';
  cout << '\n';
}
