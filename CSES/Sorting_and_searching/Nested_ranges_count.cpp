#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

struct Range{
  int Left, Right, Index;
  Range(int L, int R, int I){
    Left = L;
    Right = R;
    Index = I;
  }
  bool operator<(const Range& other) const{
    if(Left != other.Left)
      return Left < other.Left;
    if(Right != other.Right)
      return Right > other.Right;
    return Index < other.Index;
  }
};

#define LL long long
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<Range> V;
  vector<int> Ans1(N), Ans2(N);
  int L, R;
  for(int i = 0; i < N; i++){
    cin >> L >> R;
    V.push_back(Range(L, R, i));
  }
  sort(V.begin(), V.end());
  ordered_set<pair<int,int>> S;
  for(int i = N - 1; i >= 0; i--){
    Ans1[V[i].Index] = S.order_of_key({V[i].Right, INT_MAX});
    S.insert({V[i].Right, i});
  }
  S.clear();
  for(int i = 0; i < N; i++){
    Ans2[V[i].Index] = S.size() - S.order_of_key({V[i].Right, -1});
    S.insert({V[i].Right, i});
  }
  for(auto&e : Ans1)
    cout << e << ' ';
  cout << '\n';
  for(auto&e : Ans2)
    cout << e << ' ';
}
