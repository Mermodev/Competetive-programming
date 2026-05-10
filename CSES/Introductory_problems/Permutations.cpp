#include<bits/stdc++.h>
using namespace std;

#define LL long long 
#define ssize(x) int(x.size())

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  if(N == 1){
    cout << 1;
    return 0;
  }
  if(N > 1 && N < 4){
    cout << "NO SOLUTION";
    return 0;
  }
  for(int i = 2; i <= N; i += 2)
    cout << i << ' ';
  for(int i = 1; i <= N; i += 2)
    cout << i << ' ';
}
