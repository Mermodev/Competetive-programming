#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    string Input;
    cin >> Input;
    bool was0 = false, was1 = false;
    string Output = "";
    for(auto&e : Input){
      if(e == '0'){
        if(was0)
          Output.push_back(e);
        was0 = true;
      }
      else{
        if(was1)
          Output.push_back(e);
        was1 = true;
      }
    }
    cout << Output << '\n';
  }
}
