---
tags:
  - dp
  - counting
  - digit_dp
---

# Counting_numbers.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;

long long memo[20][11];
bool vis[20][11];

long long dp(int digit, int pos, int limiter, const string &base){
  if(pos == (int)base.size())
    return 1;
  if(limiter == 10 && vis[pos][digit + 1])
    return memo[pos][digit + 1];
  long long Res = 0;
  for(int i = 0; i <= min(9, limiter - 1); i++)
    if(i != digit){
      int nextDigit = (digit == -1 && i == 0) ? -1 : i;
      Res += dp(nextDigit, pos + 1, 10, base);
    }
  if(limiter != 10 && limiter != digit){
    int nextDigit = (digit == -1 && limiter == 0) ? -1 : limiter;
    if(pos + 1 == (int)base.size())
      Res += 1;
    else
      Res += dp(nextDigit, pos + 1, (int)(base[pos + 1] - '0'), base);
  }
  if(limiter == 10){
    vis[pos][digit + 1] = true;
    memo[pos][digit + 1] = Res;
  }
  return Res;
}

long long f(long long N){
  if(N < 0) return 0;
  string s = to_string(N);
  memset(vis, 0, sizeof(vis));
  return dp(-1, 0, (int)(s[0] - '0'), s);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  long long a, b;
  cin >> a >> b;
  cout << f(b) - f(a - 1) << '\n';
}
```
