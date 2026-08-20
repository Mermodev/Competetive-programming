#include<bits/stdc++.h>
using namespace std;

int main(){
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool Combi[4] = {true, true, true, true};
    char Sign[4][4] = {{'0','0','1','1'}, {'0','1','1','0'}, {'1','0','0','1'}, {'1','1','0','0'}};
    for(int i = 0; i < N; i++){
      if(S[i] == '?')
        continue;
      for(int k = 0; k < 4; k++)
        if(S[i] != Sign[k][i % 4])
          Combi[k] = false;
    }
    int Ans = 0;
    for(auto&b : Combi)
      if(b) Ans++;
    cout << Ans <<'\n';
  }
}
