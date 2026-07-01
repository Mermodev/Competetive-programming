#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int l, r, x, s, e;
    cin >> l >> r >> x >> s >> e;
    if(s == e)
      cout << 0 << '\n';
    else if(abs(s - e) >= x)
      cout << 1 << '\n';
    else if((abs(s - l) >= x && abs(l - e) >= x) || (abs(s - r) >= x && abs(r - e) >= x))
      cout << 2 << '\n';
    else if((abs(s - l) < x && abs(s - r) < x) || (abs(e - l) < x && abs(e - r) < x))
      cout << -1 << '\n';
    else 
      cout << 3 << '\n';
  }
}
