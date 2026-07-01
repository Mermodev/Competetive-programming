#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, tmp;
    cin >> N;
    stack<int> S;
    while(N--){
      cin >> tmp;
      if(S.empty() || tmp > S.top()){
        S.push(tmp);
        continue;
      }
      int Rem = S.top();
      while(!S.empty() && tmp < S.top())
        S.pop();
      S.push(Rem);
    }
    cout << S.size() << '\n';
  }
}
