#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<pair<int, int>> V(N);
  for(int i = 0; i < N; i++){
    cin >> V[i].first;
    V[i].second = i;
  }
  sort(V.begin(), V.end());
  int Cycles = 1, PrevPos = -1;
  for(int i = 0; i < N; i++){
    if(V[i].second < PrevPos)
      Cycles++;
    PrevPos = V[i].second;
  }
  cout << Cycles << '\n';
}
