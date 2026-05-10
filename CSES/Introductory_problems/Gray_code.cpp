#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ssize(x) int(x.size())

string SwapChar(string S, int Pos){
  if(S[Pos] == '0') 
    S[Pos] = '1';
  else 
    S[Pos] = '0';
  return S;
}

void dfs(string Curr, map<string, bool>&Vis){
  cout << Curr << '\n';
  Vis[Curr] = true;
  for(int i = 0; i < ssize(Curr); i++)
    if(!Vis[SwapChar(Curr, i)])
      dfs(SwapChar(Curr, i), Vis);
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  LL N;
  cin >> N;
  map<string, bool> Vis;
  dfs(string(N, '0'), Vis);
}
