#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  set<int> S;
  for(int i = 1; i <= N; i++)
    S.insert(i);
  if(S.size() == 1){
    cout << 1 << '\n';
    return 0;
  }
  auto p = next(S.begin());
  while(true){
    cout << *p << ' ';
    p = S.erase(p);
    if(S.empty())
      break;
    if(p == S.end())
      p = S.begin();
    p++;
    if(p == S.end())
      p = S.begin();
  }
}
