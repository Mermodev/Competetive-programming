#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, In, Out = 0;
  cin >> N;
  map<int, bool> Vis;
  while(N--){
    cin >> In;
    if(!Vis[In]){
      Out++;
      Vis[In] = true;
    }
  }
  cout << Out << '\n';
}
