#include<bits/stdc++.h>
using namespace std;

int id(char&x, char&y){
  if (x == '0' && y == '0') return 0;
  if (x == '0' && y == '1') return 1;
  if (x == '1' && y == '0') return 2;
  return 3;
}

int main(){
  int T;
  cin >> T;
  while(T--){
    int N, Q;
    cin >> N >> Q;
    string A, B;
    cin >> A >> B;
    vector<vector<int>> Pref(N + 1, vector<int>(4, 0));
    for(int i = 0; i < N; i++){
      Pref[i + 1] = Pref[i];
      Pref[i + 1][id(A[i], B[i])]++;
    }
    while(Q--){
      int l, r;
      cin >> l >> r;
      int Common = Pref[r][3] - Pref[l - 1][3] + Pref[r][0] - Pref[l - 1][0];
      int Different = abs(Pref[r][1] - Pref[l - 1][1] - Pref[r][2] + Pref[l - 1][2]);
      cout << (Common >= Different ? "YES\n" : "NO\n");
    }
  }
}
