#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define sz(x) (LL)(x.size())

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, M;
  cin >> N >> M;
  vector<pair<int, int>> V(N);
  for(int i = 0; i < N; i++){
    cin >> V[i].first;
    V[i].second = i;
  }
  sort(V.begin(), V.end());
  for(int c = 0; c < N - 2; c++){
    LL Rem = M - V[c].first;
    int a = c + 1, b = N - 1;
    while(a != b){
      if(V[a].first + V[b].first > Rem)
        b--;
      else if(V[a].first + V[b].first < Rem)
        a++;
      else{
        cout << V[a].second + 1 << ' ' << V[b].second + 1 << ' ' << V[c].second + 1 << '\n';
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
