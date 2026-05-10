#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ssize(x) int(x.size())

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, CurrVal, T, Ans = 0;
  cin >> N >> CurrVal;
  for(int i = 1; i < N; i++){
    cin >> T;
    Ans += max(0ll, CurrVal - T);
    CurrVal = max(CurrVal, T);
  }
  cout << Ans;
}
