#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    vector<int> V(3);
    for(auto&e : V)
      cin >> e;
    sort(V.begin(), V.end());
    cout << min(V[2] - V[0], V[1]) << '\n';
  }
}
