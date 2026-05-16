#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, Sum = 0;
  cin >> N;
  vector<LL> V(N);
  for(auto&e : V){
    cin >> e;
    Sum += e;
  }
  vector<bool> dp(Sum + 1);
  dp[0] = true;
  for(int i = 0; i < N; i++)
    for(int x = Sum; x >= V[i]; x--)
      dp[x] = dp[x] | dp[x - V[i]];
  LL Ans = 0;
  for(int i = 1; i <= Sum; i++)
    if(dp[i]) 
      Ans++;
  cout << Ans << '\n';
  for(int i = 1; i <= Sum; i++)
    if(dp[i])
      cout << i << ' ';
}
