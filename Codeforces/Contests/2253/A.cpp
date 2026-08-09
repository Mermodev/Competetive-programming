#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    long long N;
    cin >> N;
    bool Prime = true;
    for(int i = 2; i < min(N + 1, (long long)sqrt(N + 1) + 3ll) && Prime; i++)
      if((N + 1) % i == 0)
        Prime = false;
    if(Prime == true)
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
}
