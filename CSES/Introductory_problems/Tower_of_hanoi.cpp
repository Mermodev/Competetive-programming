#include<bits/stdc++.h>
using namespace std;

#define LL long long 

void Solve(int Start, int Trash, int Destination, int Depth){
  if(Depth == 1){
    cout << Start << ' ' << Destination << '\n';
  }
  else{
    Solve(Start, Destination, Trash, Depth - 1);
    cout << Start << ' ' << Destination << '\n';
    Solve(Trash, Start, Destination, Depth - 1);
  }
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  cout << ((1 << N) - 1) << '\n';
  Solve(1, 2, 3, N);
}
