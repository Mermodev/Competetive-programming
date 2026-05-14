#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, K, Distinct = 1, Out = 1;
  cin >> N >> K;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  map<int, LL> Amount;
  LL r = 0, l = 0;
  Amount[V[r]] = 1;
  while(r < N - 1){
    r++;
    if(!Amount[V[r]])
      Distinct++;
    Amount[V[r]]++;
    while(Distinct > K){
      Amount[V[l]]--;
      if(!Amount[V[l]])
        Distinct--;
      l++;
    }
    Out += r - l + 1;
  }
  cout << Out << '\n';
}
