#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  string S;
  cin >> S;
  int OddAmt = 0;
  vector<int> Amt(26);
  for(auto&e : S){
    Amt[e - 'A']++;
    if(Amt[e - 'A'] % 2){
      OddAmt++;
    }
    else 
      OddAmt--;
  }
  if(OddAmt > 1){
    cout << "NO SOLUTION\n";
    return 0;
  }
  for(int i = 0; i < 26; i++)
    for(int p = 0; p < Amt[i] / 2; p++)
      cout << char('A' + i);
  for(int i = 0; i < 26; i++)
    if(Amt[i] % 2)
      cout << char('A' + i);
  for(int i = 25; i >= 0; i--)
    for(int p = 0; p < Amt[i] / 2; p++)
      cout << char('A' + i);
}
