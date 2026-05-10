#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ssize(x) int(x.size())

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N, Remaining;
  vector<LL> Set1, Set2;
  cin >> N;
  Remaining = (N * (N + 1)) / 2;
  if(Remaining % 2){
    cout << "NO\n";
    return 0;
  }
  Remaining /= 2;
  while(N){
    if(Remaining >= N){
      Set1.emplace_back(N);
      Remaining -= N;
    }
    else 
      Set2.emplace_back(N);
    N--;
  }
  cout << "YES\n" << ssize(Set1) << '\n';
  for(auto&e : Set1)
    cout << e << ' ';
  cout << '\n' << ssize(Set2) << '\n';
  for(auto&e : Set2)
    cout << e << ' ';
}
