#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  vector<LL> V(N);
  for(auto&e : V)
    cin >> e;
  vector<LL> dp;
  for(auto&e : V){
    auto it = lower_bound(dp.begin(), dp.end(), e);
    if(it == dp.end())
      dp.push_back(e);
    else
      *it = e;
  }
  cout << dp.size() << '\n';
}
