#include<bits/stdc++.h>
using namespace std;

void dfs(int C, int P, vector<vector<int>>&G, vector<int>&Roots, int&Root){
  Roots[C] = Root;
  for(auto&e : G[C])
    if(e != P && Roots[e] == -1)
      dfs(e, C, G, Roots, Root);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, a, b, prev;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    G[--a].emplace_back(--b);
    G[b].emplace_back(a);
  }
  vector<int> Roots(N, -1);
  vector<pair<int, int>> Out;
  for(int i = 0; i < N; i++)
    if(Roots[i] == -1){
      dfs(i, -1, G, Roots, i);
      if(i)
        Out.emplace_back(make_pair(i + 1, prev + 1));
      prev = i;
    }
  cout << Out.size() << '\n';
  for(auto&e : Out)
    cout << e.first << ' ' << e.second << '\n';
}
