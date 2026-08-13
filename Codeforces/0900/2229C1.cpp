#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<int> V(N);
    for(auto&e : V)
      cin >> e;
    bool Swapped = false;
    vector<int> Ans;
    for(int i = N - 1; i >= 0; i--){
      if(Swapped ^ (V[i] > 0)){
        Swapped = !Swapped;
        Ans.emplace_back(i + 1);
      }
    }
    cout << Ans.size() << '\n';
    for(auto&e : Ans)
      cout << e << ' ';
    cout << '\n';
  }
}
