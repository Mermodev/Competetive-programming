#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL Q;
  cin >> Q;
  while(Q--){
    LL A, B;
    cin >> A >> B;
    if((2 * A - B) % 3 != 0 || (2 * B - A) % 3 != 0 || A > (2 * B) || B > (2 * A))
      cout << "NO\n";
    else 
      cout << "YES\n";
  }
}
