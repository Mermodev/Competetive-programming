#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL FastPow(LL Base, LL Exp, LL Mod){
  LL Out = 1;
  while(Exp){
    if(Exp % 2)
      Out = (Out * Base) % Mod;
    Base = (Base * Base) % Mod;
    Exp = Exp >> 1;
  }
  return Out;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  cout << FastPow(2, N, 1000000007);
}
