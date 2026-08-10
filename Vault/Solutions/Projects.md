---
tags:
  - dp
  - binsearch
---

# Projects.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  vector<LL> A(N), B(N), P(N), C;
  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i] >> P[i];
    B[i]++;
    C.push_back(A[i]);
    C.push_back(B[i]);
  }
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());
  for(int i = 0; i < N; i++){
    A[i] = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
    B[i] = lower_bound(C.begin(), C.end(), B[i]) - C.begin();
  }
  int M = C.size();
  vector<vector<pair<LL,LL>>> v(M);
  for(int i = 0; i < N; i++)
    v[B[i]].push_back({A[i], P[i]});
  vector<LL> dp(M);
  for(int i = 0; i < M; i++){
    if(i) dp[i] = dp[i - 1];
    for(auto &e : v[i])
      dp[i] = max(dp[i], dp[e.first] + e.second);
  }
  cout << dp[M - 1] << '\n';
}
```
