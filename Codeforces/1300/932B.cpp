#include<bits/stdc++.h>
using namespace std;

int Prod(int X){
  int Res = 1;
  while(X){
    if(X % 10 != 0)
      Res *= X % 10;
    X /= 10;
  }
  return Res;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  vector<vector<int>> pref(1000050, vector<int>(10));
  for(int i = 1; i < 1000050; i++){
    int Copy = i;
    while(Copy >= 10)
      Copy = Prod(Copy);
    pref[i] = pref[i - 1];
    pref[i][Copy]++;
  }
  while(Q--){
    int A, B, K;
    cin >> A >> B >> K;
    cout << pref[B][K] - pref[A - 1][K] << '\n';
  }
}
