#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  long long N;
  cin >> N;
  for(long long X = 1; X < sqrt(N) + 10; X++){
    if((N - 1) % X != 0)
      continue;
    long long Y = (N - 1) / X - X - 1;
    if(Y % 2 != 0 || (X*X + X*Y + X + 1) != N || Y <= 0)
      continue;
    else{
      cout << X << ' ' << Y / 2 << '\n';
      return 0;
    }
  }  
  cout << "NO\n";
}
