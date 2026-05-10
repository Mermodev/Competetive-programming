#include<bits/stdc++.h>
using namespace std;

#define LL long long 
#define ssize(x) (LL)(x.size())

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N;
  cin >> N;
  vector<vector<int>> V(N, vector<int>(N, -1));
  vector<int> dY = {-2, -2, -1, +1, +2, +2, +1, -1};
  vector<int> dX = {-1, +1, +2, +2, +1, -1, -2, -2};
  V[0][0] = 0;
  queue<pair<int,int>> Q;
  Q.push({0, 0});
  while(!Q.empty()){
    for(int i = 0; i < 8; i++){
      if(Q.front().first + dX[i] > -1 && Q.front().second + dY[i] > -1 &&\
         Q.front().first + dX[i] < N && Q.front().second + dY[i] < N &&\
         V[Q.front().second + dY[i]][Q.front().first + dX[i]] == -1){
        Q.push({Q.front().first + dX[i], Q.front().second + dY[i]});
        V[Q.front().second + dY[i]][Q.front().first + dX[i]] = V[Q.front().second][Q.front().first] + 1;
      }
    }
    Q.pop();
  }
  for(auto&e : V){
    for(auto&g : e)
      cout << g << ' ';
    cout << '\n';
  }
}
