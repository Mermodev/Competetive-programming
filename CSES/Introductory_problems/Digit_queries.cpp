#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL FastPow(LL Base, LL Exp){
  LL Out = 1;
  while(Exp){
    if(Exp % 2)
      Out *= Base;
    Base *= Base;
    Exp >>= 1;
  }
  return Out;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    LL N;
    cin >> N;
    LL NumLen = 1, NumAmt = 9;
    while(N > NumAmt * NumLen){
      N -= NumAmt * NumLen;
      NumAmt *= 10;
      NumLen++;
    }
    long long index = N % NumLen;
    long long res = FastPow(10, (NumLen - 1)) + (N - 1) / NumLen;
    if (index != 0)
        res = res / FastPow(10, NumLen - index);
     cout << res % 10 << '\n';
  }
  return 0;
}
