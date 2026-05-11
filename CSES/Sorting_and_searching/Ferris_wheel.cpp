#include<bits/stdc++.h>
using namespace std;

#define ssize(x) (int)(x.size())

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, X, T, Out = 0;
  cin >> N >> X;
  multiset<int> Children;
  while(N--){
    cin >> T;
    Children.insert(T);
  }
  N = ssize(Children);
  while(!Children.empty()){
    Out++;
    T = *prev(Children.end());
    Children.erase(prev(Children.end()));
    auto p = Children.upper_bound(X - T);
    if(p == Children.begin())
      continue;
    p--;
    Children.erase(p);
  }
  cout << Out << '\n';
}
