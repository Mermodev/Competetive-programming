#include<bits/stdc++.h>
using namespace std;

#define LL long long 
LL MOD = 1000000007;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  __int128 Sum;
  LL N;
  cin >> N;
  Sum = (N * (N + 1)) / 2ll;
  if(Sum % 2){
    cout << 0 << '\n';
    return 0;
  }
  Sum /= 2;
  vector<LL> dp(Sum + 1);
  dp[0] = 1;
  for(int i = 1; i < N; i++)
    for(int x = Sum; x >= i; x--)
      dp[x] = (dp[x] + dp[x - i]) % MOD;
  cout << dp[Sum];
}
