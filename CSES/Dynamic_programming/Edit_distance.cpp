#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define sz(x) (LL)(x.size())

LL tMin(LL a, LL b, LL c){
  return min(min(a, b), c);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  string S1, S2;
  cin >> S1 >> S2;
  vector<vector<LL>> dp(sz(S1) + 1, vector<LL>(sz(S2) + 1));
  for(int i = 0; i <= sz(S1); i++)
    dp[i][0] = i;
  for(int i = 0; i <= sz(S2); i++)
    dp[0][i] = i;
  for(int p1 = 1; p1 <= sz(S1); p1++)
    for(int p2 = 1; p2 <= sz(S2); p2++)
      dp[p1][p2] = tMin(dp[p1 - 1][p2] + 1, dp[p1][p2 - 1] + 1, dp[p1 - 1][p2 - 1] + (S1[p1 - 1] != S2[p2 - 1]));
  cout << dp[sz(S1)][sz(S2)];
}
