#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N;
  cin >> N;
  vector<tuple<int,int,int>> V(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    V[i] = {a, b, i};
  }
  sort(V.begin(), V.end());
  multiset<pair<int,int>> Exits;
  vector<int> Ans(N);
  int Rooms = 0;
  for (auto &[start, end, idx] : V) {
    auto it = Exits.lower_bound({start, 0});
    if (it == Exits.begin()) {
      Rooms++;
      Ans[idx] = Rooms;
      Exits.insert({end, Rooms});
    } else {
      it--;
      int room = it->second;
      Exits.erase(it);
      Ans[idx] = room;
      Exits.insert({end, room});
    }
  }
  cout << Rooms << '\n';
  for (int x : Ans)
    cout << x << ' ';
  cout << '\n';
}
