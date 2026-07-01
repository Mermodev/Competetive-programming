#include<bits/stdc++.h>
using namespace std;

string Sanitize(string&In){
  string Out = "";
  for(auto e : In){
    if(e == ';' || e == '-' || e == '_')
      continue;
    Out.push_back(tolower(e));
  }
  return Out;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  vector<string> Base(3);
  for(auto&e : Base){
    cin >> e;
    e = Sanitize(e);
  }
  int Q;
  cin >> Q;
  string In;
  while(Q--){
    cin >> In;
    In = Sanitize(In);
    vector<int> Order = {0, 1, 2};
    string Compare;
    do{
      Compare = Base[Order[0]] + Base[Order[1]] + Base[Order[2]];
      if(Compare == In)
        break;
    }
    while(next_permutation(Order.begin(), Order.end()));
    if(Compare == In)
      cout << "ACC\n";
    else 
      cout << "WA\n";
  }
}
