#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<long long> V(N), Ans;
    for(auto&e : V)
      cin >> e;
    long long Best_score = 0, Best_pos = -1;
    long long Prev_sum = 0, Rest = 0;
    for(auto&e : V)
      Best_score += e;
    Rest = Best_score;
    for(int i = 0; i < N; i++){
      Rest -= V[i];
      if(V[i] > 0 && Best_score < Prev_sum - V[i] + Rest){
        Best_score = Prev_sum - V[i] + Rest;
        Best_pos = i;
      }
      Prev_sum += abs(V[i]);
    }
    bool Switched = false;
    for(int j = Best_pos - 1; j >= 0; j--)
      if(Switched ^ (V[j] > 0)){
        Ans.emplace_back(j + 1);
        Switched = !Switched;
      }
    if(Best_pos != -1)
      Ans.emplace_back(Best_pos + 1);
    cout << Ans.size() << '\n';
    for(auto&e : Ans)
      cout << e << ' ';
    cout << '\n';
  }
}
