#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, Temp, Score = 1;
  cin >> N;
  map<int, LL> Amount;
  for(int i = 0; i < N; i++){
    cin >> Temp;
    Amount[Temp]++;
  }
  for(auto&e : Amount)
    Score = (Score * (e.second + 1)) % 1000000007;
  cout << Score - 1 << '\n';
}
