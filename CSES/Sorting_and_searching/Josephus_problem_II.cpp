#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, M, Position = 0;
  cin >> N >> M;
  ordered_set S;
  for(int i = 1; i <= N; i++)
    S.insert(i);
  while(!S.empty()){
    Position = (Position + M) % S.size();
    auto p = S.find_by_order(Position);
    cout << *p << ' ';
    S.erase(p);
  }
}
