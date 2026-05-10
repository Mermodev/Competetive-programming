#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, A, B;
    cin >> N >> A >> B;
    if(N == 1 && A == 0 && B == 0){
      cout << "YES\n1\n1\n";
      continue;
    }
    if((A > 0 && B == 0) || (A == 0 && B > 0) || A + B > N){
      cout << "NO\n";
      continue;
    }
    vector<int> G1, G2;
    for(int i = B + 1; i < A + B + 1; i++){
      G1.emplace_back(i);
      G2.emplace_back(i - B);
    }
    for(int i = A + 1; i < A + B + 1; i++){
      G1.emplace_back(i - A);
      G2.emplace_back(i);
    }
    for(int i = A + B + 1; i < N + 1; i++){
      G1.emplace_back(i);
      G2.emplace_back(i);
    }
    cout << "YES\n";
    for(auto&e : G1)
      cout << e << ' ';
    cout << '\n';
    for(auto&e : G2)
      cout << e << ' ';
    cout << '\n';
  }
}
