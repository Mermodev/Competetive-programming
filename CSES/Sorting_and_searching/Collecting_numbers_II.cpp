#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int N, Q;
  cin >> N >> Q;
  vector<int> Real(N);
  vector<pair<int, int>> V(N);
  for(int i = 0; i < N; i++){
    cin >> V[i].first;
    Real[i] = V[i].first - 1;
    V[i].second = i;
  }
  sort(V.begin(), V.end());
  int Cycles = 1, PrevPos = -1;
  for(int i = 0; i < N; i++){
    if(V[i].second < PrevPos)
      Cycles++;
    PrevPos = V[i].second;
  }
  while(Q--){
    int A, B;
    cin >> A >> B;
    swap(Real[A - 1], Real[B - 1]);
    int Temp = A;
    A = Real[B - 1];
    B = Real[Temp - 1];
    if(A > B) swap(A, B);
    if(A > 0 && B != A - 1)
      if(V[A].second < V[A - 1].second) Cycles--;
    if(B > 0 && A != B - 1)
      if(V[B].second < V[B - 1].second) Cycles--;
    if(A < N - 1 && B != A + 1)
      if(V[A + 1].second < V[A].second) Cycles--;
    if(B < N - 1)
      if(V[B + 1].second < V[B].second) Cycles--;
    if(B == A + 1)
      if(V[B].second < V[A].second) Cycles--;
    swap(V[A].second, V[B].second);
    if(A > 0 && B != A - 1)
      if(V[A].second < V[A - 1].second) Cycles++;
    if(B > 0 && A != B - 1)
      if(V[B].second < V[B - 1].second) Cycles++;
    if(A < N - 1 && B != A + 1)
      if(V[A + 1].second < V[A].second) Cycles++;
    if(B < N - 1)
      if(V[B + 1].second < V[B].second) Cycles++;
    if(B == A + 1)
      if(V[B].second < V[A].second) Cycles++;
    cout << Cycles << '\n';
  }
}
