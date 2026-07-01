#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  long long N, Left = 0, Right = 0;
  cin >> N;
  vector<int> Ans;
  while(N != 0){
    if(Left < Right){
      Ans.emplace_back(N);
      Left += N;
    }
    else
      Right += N;
    N--;
  }
  cout << abs(Left - Right) << '\n';
  cout << Ans.size() << ' ';
  for(auto&e : Ans)
    cout << e << ' ';
  cout << '\n';
}
