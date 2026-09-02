#include<bits/stdc++.h>
using namespace std;

struct Order{
  int Sign, u, v;
};

bool Assign_graph(vector<vector<int>>&G, vector<Order>&Orders, int&N, int&M, vector<int>&Sign){
  for(auto&Current : Orders){
    if(Sign[Current.u] != Sign[Current.v]){
      int From = (Sign[Current.u] == Current.Sign) ? Current.u : Current.v;
      int To = Current.u + Current.v - From;
      G[From].emplace_back(To);
    }
    else if(Sign[Current.u] != Current.Sign)
      return false;
  }
  return true;
}

bool dfs(int&C, int&Curr, vector<vector<int>>&G, vector<int>&Val, vector<int>&State){
  State[C] = 1;
  for(auto&e : G[C]){
    if(State[e] == 1)
      return false;
    if(State[e] == 0 && !dfs(e, Curr, G, Val, State))
      return false;
  }
  State[C] = 2;
  Val[C] = Curr++;
  return true;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, M;
    cin >> N >> M;
    Order Current;
    vector<int> Sign(N);
    vector<Order> Orders;
    for(int i = 0; i < M; i++){
      cin >> Current.Sign >> Current.u >> Current.v;
      if(--Current.u == --Current.v)
        Sign[Current.u] = Current.Sign;
      else 
        Orders.push_back(Current);
    }
    vector<vector<int>> G(N);
    if(!Assign_graph(G, Orders, N, M, Sign)){
      cout << "NO\n";
      continue;
    } 
    int Curr = 1;
    vector<int> Val(N, -1), State(N, 0);
    bool Ok = true;
    for(int i = 0; i < N && Ok; i++)
      if(State[i] == 0)
        Ok = dfs(i, Curr, G, Val, State);
    if(!Ok){
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for(int i = 0; i < N; i++)
      cout << ((Sign[i] == 1) ? Val[i] : -Val[i]) << ' ';
    cout << '\n';
  }
}
