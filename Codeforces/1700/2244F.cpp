#include<bits/stdc++.h>
using namespace std;

bool dfs(int C, vector<vector<int>>&G, vector<int>&Vis, vector<int>&Leaf, vector<pair<int, int>>&Children){
  Vis[C] = true;
  int Inversions = 0;
  int Prev = -INT_MAX, First = -INT_MAX;
  int Min_child = INT_MAX, Max_child = -INT_MAX;
  if(Leaf[C] != 0)
    return true;
  for(auto&e : G[C])
    if(!Vis[e]){
      if(!dfs(e, G, Vis, Leaf, Children))
        return false;
      if(Children[e].first < Prev)
        Inversions++;
      if(First == -INT_MAX)
        First = Children[e].first;
      Prev = Children[e].second;
      Min_child = min(Min_child, Children[e].first);
      Max_child = max(Max_child, Children[e].second);
    }
  Children[C] = make_pair(Min_child, Max_child);
  if(First < Prev)
    Inversions++;
  if(Inversions > 1)
    return false;
  return true;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<int> Vis(N), Leaf(N);
    vector<pair<int, int>> Children(N);
    for(int i = 1; i < N; i++){
      int Where;
      cin >> Where;
      G[i].emplace_back(--Where);
      G[Where].emplace_back(i);
    }
    for(int i = 0; i < N; i++){
      cin >> Leaf[i];
      Children[i] = make_pair(Leaf[i], Leaf[i]);
    }
    for(int i = 0; i < N; i++)
      sort(G[i].begin(), G[i].end());
    if(!dfs(0, G, Vis, Leaf, Children))
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
