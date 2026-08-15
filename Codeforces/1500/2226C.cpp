#include<bits/stdc++.h>
using namespace std;

bool Check(vector<int>&V, int&M){
  vector<int> Good(0), Bad(0);
  for(int i = 0; i < V.size(); i++){
    if(V[i] > M || (Good.size() != 0 && Good[Good.size() - 1] == V[i]))
      Bad.emplace_back((V[i] - 1) / 2);
    else 
      Good.emplace_back(V[i]);
  }
  int Good_pnt = 0, Bad_pnt = 0;
  for(int i = 0; i <= M; i++){
    if(Good_pnt < Good.size() && i == Good[Good_pnt])
      Good_pnt++;
    else{
      if(Bad_pnt == Bad.size())
        return false;
      while(Bad[Bad_pnt] < i){
        Bad_pnt++;
        if(Bad_pnt == Bad.size())
          return false;
      }
      Bad_pnt++;
    }
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
    for(auto&e : V)
      cin >> e;
    sort(V.begin(), V.end());
    int L = 0, R = V[N - 1];
    int M = (L + R) / 2;
    while(R - L > 1){
      if(Check(V, M))
        L = M;
      else 
        R = M - 1;
      M = (L + R) / 2;
    }
    cout << (Check(V, R) ? R : L) + 1 << '\n';
  }
}
