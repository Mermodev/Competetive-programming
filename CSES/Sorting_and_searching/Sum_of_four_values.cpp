#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M;
  cin >> N >> M;
  vector<int> V(N);
  unordered_map<int, pair<int, int>> Idx;
  for(auto&e : V)
    cin >> e;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      auto curr = Idx[M - V[i] - V[j]];
      if(curr != make_pair(0, 0) && curr.first != i + 1 && curr.second != j + 1){
        cout << i + 1 << ' ' << j + 1 << ' ' << curr.first << ' ' << curr.second << '\n';
        return 0;
      }
    }
    for(int j = i - 1; j >= 0; j--)
      Idx[V[i] + V[j]] = {j + 1, i + 1};
  }
  cout << "IMPOSSIBLE\n";
}
