#include<bits/stdc++.h>
using namespace std;

#define LL long long 
LL MOD = 1000000007;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  vector<pair<LL, LL>> dp(1000001);
  dp[1].first = 1;
  dp[1].second = 1;
  for(int i = 2; i <= 1000000; i++){
    dp[i].first = (4 * dp[i - 1].first + dp[i - 1].second) % MOD;
    dp[i].second = (dp[i - 1].first + 2 * dp[i - 1].second) % MOD;
  }
  LL Q, N;
  cin >> Q;
  while(Q--){
    cin >> N;
    cout << (dp[N].first + dp[N].second) % MOD << '\n';
  }
}
