#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, Maximum_val = 0;
    cin >> N;
    vector<int> V(N);
    for(auto&e : V)
      cin >> e;
    cout << ((N == 1) ? V[0] : gcd(V[0], V[N - 1])) << '\n';
  }
}
