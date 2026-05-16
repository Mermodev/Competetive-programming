#include <bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<LL> V(N);
  LL Sum = 0;
  for (auto&e:V) {
    cin >> e;
    Sum += e;
  }
  vector<vector<LL>> dp(N, vector<LL>(N));
  for (int i = 0; i < N; i++)
    dp[i][i] = V[i];
  for (int len = 2; len <= N; len++) {
    for (int l = 0; l + len - 1 < N; l++) {
      int r = l + len - 1;
      dp[l][r] = max( V[l] - dp[l + 1][r], V[r] - dp[l][r - 1]);
    }
  }
  cout << (Sum + dp[0][N - 1]) / 2 << '\n';
}
