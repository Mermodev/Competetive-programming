#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, BestDiff = INT_MAX;
  cin >> N;
  vector<int> V(N);
  for(auto&e : V)
    cin >> e;
  for(int Mask = 0; Mask < (1 << N); Mask++){
    int CurrMask = Mask;
    LL CurrSum = 0;
    for(int i = 0; i < N; i++){
      if(CurrMask % 2)
        CurrSum += V[i];
      else 
        CurrSum -= V[i];
      CurrMask >>= 1;
    }
    CurrSum = abs(CurrSum);
    BestDiff = min(BestDiff, CurrSum);
  }
  cout << BestDiff;
}
