#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M, Out = 0;
  cin >> N >> M;
  vector<pair<int, int>> Mov(N);
  for(auto&e : Mov)
    cin >> e.second >> e.first;
  sort(Mov.begin(), Mov.end());
  multiset<LL> People;
  while(M--)
    People.insert(0);
  for(int i = 0; i < N; i++){
    auto p = People.upper_bound(Mov[i].second);
    if(p == People.begin())
      continue;
    People.erase(--p);
    People.insert(Mov[i].first);
    Out++;
  }
  cout << Out << '\n';
}
