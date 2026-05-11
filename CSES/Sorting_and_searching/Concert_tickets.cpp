#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, Temp;
  cin >> N >> M;
  multiset<int> T;
  vector<pair<int, int>> C(M);
  for(int i = 0; i < N; i++){
    cin >> Temp;
    T.insert(Temp);
  }
  for(int i = 0; i < M; i++){
    cin >> Temp;
    C[i] = {Temp, i};
  }
  //sort(C.begin(), C.end());
  vector<int> Out(M);
  for(int i = 0; i < M; i++){
    auto p = T.upper_bound(C[i].first);
    if(p == T.begin())
      Out[C[i].second] = -1;
    else{
      Out[C[i].second] = *prev(p);
      T.erase(prev(p));
    }
  }
  for(auto&e : Out)
    cout << e << '\n';
}
