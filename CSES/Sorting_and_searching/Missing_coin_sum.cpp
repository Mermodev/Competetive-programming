#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  sort(V.begin(), V.end());
  LL Range = 0;
  for(int i = 0; i < N; i++){
    if(Range + 1 >= V[i])
      Range += V[i];
    else{
      cout << Range + 1 << '\n';
      return 0;
    }
  }
  cout << Range + 1 << '\n';
}
