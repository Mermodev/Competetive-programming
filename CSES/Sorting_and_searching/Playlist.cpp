#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, MaxLen = 1;
  cin >> N;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  int L = 0, R = 0;
  map<int, int> Count;
  Count[V[L]]++;
  bool Cont = true;
  while(R < N && Cont){
    while(Count[V[R]] < 2 && Cont){
      MaxLen = max(MaxLen, R - L + 1);
      R++;
      if(R == N){
        Cont = false;
        break;
      }
      Count[V[R]]++;
    } 
    while(Cont && Count[V[R]] == 2){
      Count[V[L]]--;
      L++;
    }
  }
  cout << MaxLen << '\n';
}
