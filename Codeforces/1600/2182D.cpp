#include<bits/stdc++.h>
using namespace std;


int main(){
  long long MOD = 998244353;
  long long Binomial[51][51];
  for(int p = 0; p < 51; p++){
    Binomial[p][0] = Binomial[p][p] = 1;
    for(int k = 1; k < p; k++)
      Binomial[p][k] = (Binomial[p - 1][k - 1] + Binomial[p - 1][k]) % MOD;
  }
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, Base;
    cin >> N >> Base;
    long long Sum = Base;
    vector<int> V(N);
    for(auto&e : V){
      cin >> e;
      Sum += e;
    }
    bool Continue = true;
    int Ones = 0, Zeros = 0;
    int Full_spend = Sum / N;
    for(auto&e : V){
      e -= Full_spend;
      if(e > 1)
        Continue = false;
      if(e == 1)
        Ones++;
      else{ 
        Zeros++;
        Base += e;
      }
    }
    int Non_spenders = Zeros - Base;
    int Spenders = N - Non_spenders;
    if(Spenders < 0 || Non_spenders < 0 || Base < 0 || !Continue){
      cout << 0 << '\n';
      continue;
    }
    long long Ans = 1;
    for(long long i = 1; i <= Spenders; i++)
      Ans = (Ans * i) % MOD;
    for(long long i = 1; i <= Non_spenders; i++)
      Ans = (Ans * i) % MOD;
    Ans = (Ans * Binomial[Zeros][Spenders - Ones]) % MOD;
    cout << Ans << '\n';
  }
}
