#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, K, Out = 0;
  cin >> N >> M >> K;
  vector<int> P(N), A(M);
  for(auto&e : P)
    cin >> e;
  for(auto&e : A)
    cin >> e;
  sort(P.begin(), P.end());
  sort(A.begin(), A.end());
  int PersonIdx = 0, ApartamentIdx = 0;
  while(PersonIdx < N && ApartamentIdx < M){
    if(P[PersonIdx] - K <= A[ApartamentIdx] && A[ApartamentIdx] <= P[PersonIdx] + K){
      Out++;
      PersonIdx++;
      ApartamentIdx++;
    }
    else if(P[PersonIdx] - K > A[ApartamentIdx]){
      ApartamentIdx++;
    }
    else{
      PersonIdx++;
    }
  }
  cout << Out;
}
