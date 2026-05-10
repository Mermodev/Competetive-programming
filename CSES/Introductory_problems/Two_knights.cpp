#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  for(LL Side = 1; Side <= Q; Side++){
    if(Side == 1){
      cout << 0 << '\n';
      continue;
    }
    LL Score = Side * Side * (Side * Side - 1);
    if(Side > 2)
      Score -= min(2ll, Side - 2) * 12 + 8 - 4;
    if(Side > 3)
      Score -= 16 + 4;
    if(Side > 4)
      Score -= (Side - 4) * 40 + 8 * (Side - 4) * (Side - 4);
    cout << Score / 2 << '\n';
  }
}
