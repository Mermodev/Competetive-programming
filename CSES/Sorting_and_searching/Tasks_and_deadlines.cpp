#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, CurrTime = 0, Score = 0;
  cin >> N;
  vector<pair<int, int>> Ranges(N);
  for(auto&e : Ranges)
    cin >> e.first >> e.second;
  sort(Ranges.begin(), Ranges.end());
  for(auto&e : Ranges){
    Score += e.second - e.first - CurrTime;
    CurrTime += e.first;
  }
  cout << Score << '\n';
}
