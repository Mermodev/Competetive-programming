#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    LL X, Y, Val;
    cin >> Y >> X;
    LL Layer = max(Y, X);
    Val = (Layer - 1) * (Layer - 1) + Layer;
    Val -= (Layer - X) * ((Layer%2)*2-1);
    Val += (Layer - Y) * ((Layer%2)*2-1);
    cout << Val << '\n';
  }
}
