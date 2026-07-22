#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(int C, int P, vector<vector<int>>&G, vector<pair<int, int>>&Dis){
  for(auto&e : G[C])
    if(e != P){
      if(Dis[C].first - Dis[e].first >= 2){
        vector<int> Ans = {e, C};
        int Curr = Dis[C].second;
        while(Curr != e){
          Ans.emplace_back(Curr);
          Curr = Dis[Curr].second;
        }
        Ans.emplace_back(e);
        reverse(Ans.begin(), Ans.end());
        return Ans;
      }
      if(Dis[e].first == INT_MAX){
        Dis[e] = make_pair(Dis[C].first + 1, C);
        vector<int> Res = dfs(e, C, G, Dis);
        if(Res.size())
          return Res;
      }
    }
  return {};
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
  vector<pair<int, int>> Dis(N, make_pair(INT_MAX, -1));
  vector<int> Res = {};
  for(int i = 0; i < N; i++)
    if(Dis[i] == make_pair(INT_MAX, -1)){
      Dis[i] = make_pair(0, -1);
      Res = dfs(i, -1, G, Dis);
      if(Res.size()){
        cout << Res.size() << '\n';
        for(auto&e : Res)
          cout << e + 1 << ' ';
        cout << '\n';
        return 0;
      }
    }
  cout << "IMPOSSIBLE\n";
}
