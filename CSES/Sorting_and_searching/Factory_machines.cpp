#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, X;
  cin >> N >> X;
  vector<LL> V(N);
  for(auto&e : V)
    cin >> e;
  LL L = 0, R = 1000000000000000000;
  LL M = (L + R) / 2;
  while(L < R){
    LL Sum = 0;
    for(auto&e : V){
      Sum += M / e;
      if(Sum >= X)
        break;
    }
    if(Sum >= X)
      R = M;
    else 
      L = M + 1;
    M = (L + R) / 2;
  }
  cout << M << '\n';
}
