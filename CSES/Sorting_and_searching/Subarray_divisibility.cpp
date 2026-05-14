#include <bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  LL N, Temp, Pref = 0, Ans = 0;
  cin >> N;
  vector<LL> V(N);
  V[0] = 1;
  for(int i = 0; i < N; i++){
    cin >> Temp;
    Pref += Temp;
    Pref = ((Pref % N) + N) % N;
    Ans += V[Pref];
    V[Pref]++;
  }
  cout << Ans << '\n';
}
