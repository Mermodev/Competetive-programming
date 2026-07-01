#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, D;
  cin >> N >> D;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  sort(V.begin(), V.end());
  long long Ans = 0;
  queue<int> Q;
  for(auto&e : V){
    while(Q.size() && Q.front() < e - D)
      Q.pop();
    Ans += Q.size() * (Q.size() - 1) / 2;
    Q.push(e);
  }
  cout << Ans << '\n';
}
