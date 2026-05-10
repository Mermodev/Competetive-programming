#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  string S;
  cin >> S;
  sort(S.begin(), S.end());
  set<string> Ans;
  do{
    Ans.insert(S);
  }  
  while(next_permutation(S.begin(), S.end()));
  cout << Ans.size() << '\n';
  for(auto&e : Ans)
    cout << e << '\n';
}
