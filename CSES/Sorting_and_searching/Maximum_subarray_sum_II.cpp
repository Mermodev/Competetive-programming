#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, a, b, Out = -1e18;
  cin >> N >> a >> b;
  vector<LL> V(N), pref(N + 1);
  for(auto&e : V)
    cin >> e;
  multiset<LL> Val;
  for(int i = 0; i < N; i++){
    pref[i + 1] = V[i] + ((i == 0) ? 0 : pref[i]);
    if(i >= a - 1)
      Val.insert(pref[i + 1 - a]);
    if(i >= b)
      Val.erase(Val.find(pref[i - b]));
    if(!Val.empty())
      Out = max(Out, pref[i + 1] - *(Val.begin()));
  }
  cout << Out << '\n';
}
