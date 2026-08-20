#include<bits/stdc++.h>
using namespace std;

bool Check(vector<int>&V, vector<bool>&Comb){
  vector<int> Left = {0, 0}, Right = {0, 0};
  for(int i = 1; i < Comb.size(); i++)
    (Comb[i]) ? Right[1]++ : Left[1]++;
  for(int i = 0; i < Comb.size(); i++){
    if(V[i] != Left[0] + Right[1] + 1)
      return false;
    if(i != Comb.size() - 1)
      (Comb[i + 1]) ? Right[1]-- : Left[1]--;
    (Comb[i]) ? Right[0]++ : Left[0]++;
  }
  return true;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<int> V(N);
    vector<bool> Curr = {0, 1}, Possible = {1, 1}, Comb1 = {0}, Comb2 = {1};
    for(auto&e : V)
      cin >> e;
    for(int i = 1; i < N; i++){
      if(V[i] == V[i - 1]){
        Curr[0] = !Curr[0];
        Curr[1] = !Curr[1];
      }
      else if(V[i] == V[i - 1] - 1){
        if(Curr[0] == 0)
          Possible[0] = false;
        if(Curr[1] == 0)
          Possible[1] = false;
        Curr = {1, 1};
      }
      else if(V[i] == V[i - 1] + 1){
        if(Curr[0] == 1)
          Possible[0] = false;
        if(Curr[1] == 1)
          Possible[1] = false;
        Curr = {0, 0};
      }
      else
        Possible = {0, 0};
      Comb1.emplace_back(Curr[0]);
      Comb2.emplace_back(Curr[1]);
    }
    if(Possible[0]) Possible[0] = Check(V, Comb1);
    if(Possible[1]) Possible[1] = Check(V, Comb2);
    cout << (Possible[0] + Possible[1]) << '\n';
  }
}
