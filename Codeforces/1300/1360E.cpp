#include<bits/stdc++.h>
using namespace std;

void Solve(vector<string>&B){
  for(int y = B.size() - 2; y >= 0; y--)
    for(int x = B.size() - 2; x >= 0; x--)
      if(B[y][x] == '1' && B[y + 1][x] != '1' && B[y][x + 1] != '1'){
        cout << "NO\n";
        return;
      }
  cout << "YES\n";
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<string> B(N);
    for(auto&e : B){
      cin >> e;
      e.push_back('1');
    }
    B.resize(B.size() + 1);
    B[N].append(N + 1, '1');
    Solve(B);
  }
}
