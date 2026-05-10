#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  LL Out = 0;
  while(N){
    N /= 5;
    Out += N;
  }
  cout << Out;
}
