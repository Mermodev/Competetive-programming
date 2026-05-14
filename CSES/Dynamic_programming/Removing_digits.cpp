#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, Copy;
  cin >> N;
  vector<LL> dp(N + 1, INT_MAX);
  dp[N] = 0;
  for(int i = N; i >= 0; i--){
    Copy = i;
    if(dp[i] == INT_MAX)
      continue;
    while(Copy){
      if(i - (Copy % 10) >= 0)
        dp[i - (Copy % 10)] = min(dp[i - (Copy % 10)], dp[i] + 1);
      Copy /= 10;
    }
  }
  cout << dp[0] << '\n';
}
