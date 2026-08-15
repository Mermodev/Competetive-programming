#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<int> V(N);
    for(auto&e : V)
      cin >> e;
    vector<int> W = V;
    sort(W.begin(), W.end());
    int Median = W[N / 2];
    vector<int> dp(N + 1, -INT_MAX);
    dp[0] = 0;
    vector<vector<int>> Count(N + 1, vector<int>(3, 0));
    for(int i = 0 ; i < N; i++){
      Count[i + 1] = Count[i];
      if(V[i] < Median)  Count[i + 1][0]++;
      if(V[i] == Median) Count[i + 1][1]++;
      if(V[i] > Median)  Count[i + 1][2]++;
      for(int j = i; j >= 0; j -= 2)
        if(Count[i + 1][1] > Count[j][1] && abs(Count[i + 1][0] - Count[j][0] - Count[i + 1][2] + Count[j][2]) < (Count[i + 1][1] - Count[j][1]))
          dp[i + 1] = max(dp[i + 1], dp[j] + 1);
    }
    cout << dp[N] << '\n';
  }
}
