#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  vector<int> dp(N + 1);
  dp[0] = 1;
  for(int i = 1; i <= N; i++)
    for(int x = i - 1; x >= max(0, i - 6); x--)
      dp[i] = (dp[i] + dp[x]) % 1000000007;
  cout << dp[N] << '\n';
}
