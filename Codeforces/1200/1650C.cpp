#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, M;
    cin >> N >> M;
    vector<pair<pair<int, int>, int>> V(M);
    for(int i = 0; i < M; i++){
      cin >> V[i].first.second >> V[i].first.first;
      V[i].second = i;
    }
    sort(V.begin(), V.end());
    vector<pair<int, int>> Out;
    long long Sum = 0;
    for(int i = 0; i < 2 * N; i++){
      Sum += V[i].first.first;
      Out.emplace_back(make_pair(V[i].first.second, V[i].second));
    }
    sort(Out.begin(), Out.end());
    cout << Sum << '\n';
    for(int i = 0; i < N; i++)
      cout << Out[i].second + 1 << ' '<< Out[2 * N - 1 - i].second + 1 << '\n';
  }
}
