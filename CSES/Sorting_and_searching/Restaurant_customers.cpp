#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, B, E, Out = 0;
  cin >> N;
  priority_queue<pair<int, int>> pQ;
  for(int i = 0; i < N; i++){
    cin >> B >> E;
    pQ.push({-B, -1});
    pQ.push({-E, 1});
  }
  int Curr = 0;
  while(!pQ.empty()){
    Curr -= pQ.top().second;
    Out = max(Out, Curr);
    pQ.pop();
  }
  cout << Out << '\n';
}
