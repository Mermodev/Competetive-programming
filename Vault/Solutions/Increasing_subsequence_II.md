---
tags:
  - segment_tree
  - dp
  - map
---

# Increasing_subsequence_II.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;

struct SegTree{
  int Size;
  vector<long long> Tree, Lazy;
  SegTree(int Size){
    this->Size = Size * 4;
    Tree.resize(this->Size);
    Lazy.resize(this->Size);
  }
  void Push(int L, int R, int Idx){
    Tree[Idx] = (Tree[Idx] + Lazy[Idx] * (R - L + 1)) % 1000000007;
    if(L != R){
      Lazy[Idx * 2] = (Lazy[Idx * 2] + Lazy[Idx]) % 1000000007;
      Lazy[Idx * 2 + 1] = (Lazy[Idx * 2 + 1] + Lazy[Idx]) % 1000000007;
    }
    Lazy[Idx] = 0;
  }
  void Update(int L, int R, int Idx, int l, int r, int v){
    Push(L, R, Idx);
    if(R < l || L > r)
      return;
    if(L >= l && R <= r){
      Lazy[Idx] = (Lazy[Idx] + v) % 1000000007;
      Push(L, R, Idx);
      return;
    }
    Update(L, (L + R) / 2, Idx * 2, l, r, v);
    Update((L + R) / 2 + 1, R, Idx * 2 + 1, l, r, v);
    Tree[Idx] = (Tree[Idx * 2] + Tree[Idx * 2 + 1]) % 1000000007;
  }
  long long Query(int L, int R, int Idx, int l, int r){
    Push(L, R, Idx);
    if(R < l || L > r)
      return 0;
    if(L >= l && R <= r)
      return Tree[Idx];
    return (Query(L, (L + R) / 2, Idx * 2, l, r) + Query((L + R) / 2 + 1, R, Idx * 2 + 1, l, r)) % 1000000007;
  }
};

int main(){
  int N;
  cin >> N;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  map<int, int> Generalise;
  vector<int> Copy = V;
  int Curr = 1;
  sort(Copy.begin(), Copy.end());
  for(auto&e : Copy)
    if(Generalise[e] == 0){
      Generalise[e] = Curr;
      Curr++;
    }
  for(auto&e : V)
    e = Generalise[e] - 1;
  SegTree dp(Curr);
  for(auto&e : V){
    long long temp = (dp.Query(0, Curr - 1, 1, 0, e - 1) + 1) % 1000000007;
    dp.Update(0, Curr - 1, 1, e, e, temp);
  }
  cout << dp.Query(0, Curr - 1, 1, 0, Curr - 1) << '\n';
}
```
