#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define LL long long
#define ssize(x) int(x.size())

#define incr(i, l, r) for(int i = (l), i < (r); i++)
#define decr(i, r, l) for(int i = (r); i >= (l);  i--)

#define pairI pair<int,int>
#define st first
#define nd second

#define graph vector<vector<int>>

template <typename T>
using ordered_set<T> = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

#ifdef DEBUG
auto&operator<<(auto&o,pair<auto,auto>p){return o<<"("<<p.first<<", "<<p.second<<")";}
auto operator<<(auto&o,auto x)->decltype(x.end(),o){o<<"{";int i=0;for(auto e:x)o<<","+!i++<<e;return o<<"}";}
#define debug(X...)cerr<<"["#X"]: ",[](auto...$){((cerr<<$<<"; "),...)<<endl;}(X)
#else
#define debug(...){}
#endif

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  //CODE HERE
  return 0;
}
