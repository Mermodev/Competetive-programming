#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<long long> V(N);
    map<long long, int> Count;
    long long Sum = 0;
    for(auto&e : V){
      cin >> e;
      Count[e]++;
      Sum += e;
    }
    long long Max = 0, MaxCnt = 0;
    for(auto&e : Count)
      if(e.second > MaxCnt){
        MaxCnt = e.second;
        Max = e.first;
      }
    if(MaxCnt <= (N + 1) / 2)
      cout << Sum << '\n';
    else{
      long long Other = N - MaxCnt;
      long long Ans = Sum - MaxCnt * Max + (Other + 2) * Max;
      cout << Ans << '\n';
    }
  }
}
