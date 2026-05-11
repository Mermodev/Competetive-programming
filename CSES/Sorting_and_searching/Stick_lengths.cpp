#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  sort(V.begin(), V.end());
  LL Med = V[N / 2], Cost = 0;
  for(auto&e : V)
    Cost += abs(e - Med);
  cout << Cost << '\n';
}
