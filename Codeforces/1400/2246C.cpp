#include<bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

int main(){
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<int> V(N);
    long long Ans = 1, stairs = 0, different = 1;
    cin >> V[0];
    for(int i = 1; i < N; i++){
      cin >> V[i];
      if(V[i] == V[i - 1])
        continue;
      different++;
      if(V[i] == V[i - 1] + 1)
        stairs++;
    }
    for(int i = 0; i < N - different; i++)
      Ans = (Ans << 1) % MOD;
    if(V[0] == -1)
      cout << (Ans * (stairs + 1)) % MOD << '\n';
    else 
      cout << Ans << '\n';
  }
}
