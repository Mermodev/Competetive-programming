#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  while(N != 1){
    cout << N << ' ';
    if(N % 2) N = N * 3 + 1;
    else      N = N / 2;
  }
  cout << N;
}
