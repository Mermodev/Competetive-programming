#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, K;
  cin >> N >> K;
  vector<LL> V(N);
  for(auto&e : V)
    cin >> e;
  LL l = 0, r = 1000000000000000;
  LL m = (l + r) / 2;
  while(l < r){
    LL Amount = 0, Sum = 1e18;
    for(int i = 0; i < N; i++){
      if(V[i] > m){
        Amount = INT_MAX;
        break;
      }
      if(Sum + V[i] > m){
        Amount++;
        Sum = 0;
      }
      Sum += V[i];
    }
    if(Amount <= K)
      r = m;
    else 
      l = m + 1;
    m = (l + r) / 2;
  }
  cout << m << '\n';
}
