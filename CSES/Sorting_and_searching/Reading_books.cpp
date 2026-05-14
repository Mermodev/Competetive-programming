#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, Temp, Max = 0, Sum = 0;
  cin >> N;
  while(N--){
    cin >> Temp;
    Max = max(Max, Temp);
    Sum += Temp;
  }
  cout << Max + ((Max <= Sum - Max) ? Sum - Max : Max) << '\n';
}
