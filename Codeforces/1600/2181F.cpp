#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    int Ones = 0;
    vector<int> V(N);
    for(auto&e : V){
      cin >> e;
      if(e == 1)
        Ones++;
    }
    if(Ones == N)
      Ones--;
    cout << ((Ones % 2 == 0) ? "Alice" : "Bob") << '\n';
  }
}
