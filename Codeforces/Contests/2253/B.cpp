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
    vector<pair<int, int>> Compress;
    Compress.emplace_back(make_pair(-1, 1));
    Compress.emplace_back(make_pair(V[0], 1));
    for(int i = 1; i < N; i++){
      if(V[i] == V[i-1])
        Compress[Compress.size() - 1].second++;
      else 
        Compress.emplace_back(make_pair(V[i], 1));
    }
    Compress.emplace_back(make_pair(-1, 1));
    long long Ans = Compress.size() - 2;
    for(int i = 1; i < Compress.size() && Ans == Compress.size() - 2; i++)
      if(Compress[i].second > 1 && Compress[i - 1].second > 1)
        Ans += 2;
    for(int i = 2; i < Compress.size() && Ans == Compress.size() - 2; i++)
      if(Compress[i - 2].second > 1 && Compress[i].first != Compress[i - 2].first && Compress[i - 1].second == 1)
        Ans += 1;
    reverse(Compress.begin(), Compress.end());
    for(int i = 2; i < Compress.size() && Ans == Compress.size() - 2; i++)
      if(Compress[i - 2].second > 1 && Compress[i].first != Compress[i - 2].first && Compress[i - 1].second == 1)
        Ans += 1;
    cout << Ans << '\n';
  }
}
