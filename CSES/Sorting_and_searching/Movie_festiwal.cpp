#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, CurrEnd = -1, Out = 0;
  cin >> N;
  vector<pair<int, int>> V(N);
  for(auto&e : V)
    cin >> e.second >> e.first;
  sort(V.begin(), V.end());
  for(int i = 0; i < N; i++){
    if(V[i].second >= CurrEnd){
      CurrEnd = V[i].first;
      Out++;
    }
  }
  cout << Out << '\n';
}
