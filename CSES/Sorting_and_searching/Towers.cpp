#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, Temp;
  cin >> N;
  multiset<int> Towers;
  for(int i = 0; i < N; i++){
    cin >> Temp;
    auto p = Towers.upper_bound(Temp);
    if(p != Towers.end())
      Towers.erase(p);
    Towers.insert(Temp);
  }
  cout << Towers.size() << '\n';
}
