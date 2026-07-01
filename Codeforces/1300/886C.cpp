#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, temp, Ans = 0;
  cin >> N;
  vector<bool> V(N + 1, false);
  for(int i = 1; i <= N; i++){
    cin >> temp;
    if(V[temp] == true){
      V[temp] = false;
      V[i] = true;
    }
    else{
      Ans++;
      V[i] = true;
    }
  }
  cout << Ans << '\n';
}
