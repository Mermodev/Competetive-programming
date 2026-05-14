#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, X, temp;
  LL prev = 0, Out = 0;
  cin >> N >> X;
  map<LL, LL> Amount;
  Amount[prev] = 1;
  for(int i = 0; i < N; i++){
    cin >> temp;
    prev += temp;
    Out += Amount[prev - X];
    Amount[prev]++;
  }
  cout << Out << '\n';
}
