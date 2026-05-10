#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL Q, T;
  cin >> Q;
  LL N = Q;
  for(int i = 1; i < Q; i++){
    cin >> T;
    N += i - T;
  }
  cout << N;
}
