#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, Temp;
  cin >> N;
  stack<pair<int, int>> S;
  S.push({-INT_MAX, 0});
  for(int i = 1; i <= N; i++){
    cin >> Temp;
    while(S.top().first >= Temp)
      S.pop();
    cout << S.top().second << ' ';
    S.push({Temp, i});
  }
  cout << '\n';
}
