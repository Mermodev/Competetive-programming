#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  pair<int, int> A, B, C;
  cin >> A.first >> A.second;
  cin >> B.first >> B.second;
  cin >> C.first >> C.second;
  cout << 3 << '\n';
  cout << B.first + C.first - A.first << ' ' << B.second + C.second - A.second << '\n';
  cout << A.first + C.first - B.first << ' ' << A.second + C.second - B.second << '\n';
  cout << A.first + B.first - C.first << ' ' << A.second + B.second - C.second << '\n';
}
