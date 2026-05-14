#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, T;
  cin >> N;
  vector<LL> pref(N);
  cin >> pref[0];
  LL Smallest = min(0ll, pref[0]), Best = pref[0];
  for(int i = 1; i < N; i++){
    cin >> T;
    pref[i] = pref[i - 1] + T;
    Best = max(Best, pref[i] - Smallest);
    Smallest = min(Smallest, pref[i]);
  }
  cout << Best << '\n';
}
