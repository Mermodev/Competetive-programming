#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<int> Pref(N, 0);
    for(int i = 0; i + 1 < N; i++)
      Pref[i + 1] = Pref[i] + (S[i] == S[i + 1] ? 1 : 0);
    while(T--){
      int l, r, k;
      cin >> l >> r >> k;
      if(l == r){
        cout << "YES\n";
        continue;
      }
      int C = Pref[r - 1] - Pref[l - 1];
      int Needed = (C + 1) / 2;
      cout << (Needed <= k ? "YES\n" : "NO\n");
    }
  }
}
