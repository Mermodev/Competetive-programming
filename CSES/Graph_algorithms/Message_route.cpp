#include<bits/stdc++.h>
using namespace std;

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
  vector<int> Parent(N, -1);
  queue<int> Q;
  Q.push(0);
  int Curr = Q.front();
  while(!Q.empty()){
    Curr = Q.front();
    Q.pop();
    for(auto&e : G[Curr])
      if(Parent[e] == -1){
        Q.push(e);
        Parent[e] = Curr;
      }
  }
  if(Parent[N - 1] == -1){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector<int> Ans = {N};
  Curr = N - 1;
  while(Curr != 0){
    Ans.emplace_back(Parent[Curr] + 1);
    Curr = Parent[Curr];
  }
  reverse(Ans.begin(), Ans.end());
  cout << Ans.size() << '\n';
  for(auto&e : Ans)
    cout << e << ' ';
  cout << '\n';
}
