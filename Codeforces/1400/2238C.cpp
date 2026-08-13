#include<bits/stdc++.h>
using namespace std;

void dfs(int C, vector<vector<int>>&G, vector<long long>&Ans, vector<long long>&Depths){
  vector<int> Child_depths = {0, 0};
  for(auto&child : G[C]){
    dfs(child, G, Ans, Depths);
    Ans[C] += Ans[child];
    Child_depths.emplace_back(Depths[child]);
  }
  sort(Child_depths.begin(), Child_depths.end());
  Ans[C] += Child_depths[Child_depths.size() - 2] + 1;
  Depths[C] = Child_depths[Child_depths.size() - 1] + 1;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<vector<int>> G(N + 1);
    for(int i = 0; i < N - 1; i++){
      int u;
      cin >> u;
      G[u].emplace_back(i + 2);
    }
    vector<long long> Ans(N + 1, 0);
    vector<long long> Depths(N + 1, -1);
    dfs(1, G, Ans, Depths);
    cout << Ans[1] << '\n';
  }
}
