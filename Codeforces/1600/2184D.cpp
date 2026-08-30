#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  int Binomial[31][31];
  for(int p = 0; p < 31; p++)
    for(int k = 0; k < 31; k++){
      if(p == 0 || k > p)
        Binomial[p][k] = 0;
      else if(p == k || k == 0)
        Binomial[p][k] = 1;
      else 
        Binomial[p][k] = Binomial[p - 1][k - 1] + Binomial[p - 1][k];
    }
  while(Q--){
    int N, K, Ans = 0;
    cin >> N >> K;
    int d = 0;
    while(N % 2 == 0){
      N >>= 1;
      d++;
    }
    for(int Size = 0; Size < d; Size++)
      for(int Ones = max(K - Size, 0); Ones <= Size; Ones++)
        Ans += Binomial[Size][Ones];
    if(d + 1 > K)
      Ans++;
    cout << Ans << '\n';
  }
}
