#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, Temp;
  cin >> N >> M;
  set<int> Lights;
  multiset<int> Distances;
  Lights.insert(0);
  Lights.insert(N);
  Distances.insert(N);
  for(int i = 0; i < M; i++){
    cin >> Temp;
    auto R = Lights.upper_bound(Temp);
    auto L = prev(R);
    Distances.erase(Distances.find(*R - *L));
    Distances.insert(*R - Temp);
    Distances.insert(Temp - *L);
    Lights.insert(Temp);
    cout << *prev(Distances.end()) << '\n';
  }
}
