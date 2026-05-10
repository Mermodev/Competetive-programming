#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ssize(x) int(x.size())

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  string S;
  cin >> S;
  if(ssize(S) == 1){
    cout << 1;
    return 0;
  }
  int MaxLen = 0, CurrLen = 1;
  for(int i = 1; i < ssize(S); i++){
    if(S[i] != S[i - 1]){
      MaxLen = max(MaxLen, CurrLen);
      CurrLen = 1;
    }
    else 
      CurrLen++;
  }
  MaxLen = max(MaxLen, CurrLen);
  cout << MaxLen;
}
