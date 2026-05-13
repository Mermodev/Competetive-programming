#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, Score = 0;
  cin >> N;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  bool B = true;
  int L = 0, R = 0;
  map<int, int> Count;
  Count[V[R]]++;
  while(R < N){
    while(Count[V[R]] < 2){
      Score += R - L + 1;
      R++;
      if(R == N){
        B = false;
        break;
      }
      Count[V[R]]++;
    }
    if(!B)
      break;
    while(Count[V[R]] == 2){
      Count[V[L]]--;
      L++;
    }
  }
  cout << Score << '\n';
}
