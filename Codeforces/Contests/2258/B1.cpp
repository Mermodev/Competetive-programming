#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Questions;
  cin >> Questions;
  while(Questions--){
    long long N, M;
    cin >> N >> M;
    vector<int> V(N);
    int MaxV = 0;
    long long Sum = 0;
    for(int i = 0; i < N; i++){
      cin >> V[i];
      MaxV = max(MaxV, V[i]);
      Sum += V[i];
    }
    vector<long long> Count(MaxV + 1, 0), Pref(MaxV + 1, 0);
    for(int i = 0; i < N; i++) Count[V[i]]++;
    for(int v = 1; v <= MaxV; v++) Pref[v] = Pref[v - 1] + Count[v];
    vector<long long> Ans;
    int K = 1;
    long long Cap = 1ll << K;
    if(Cap >= (long long)MaxV){
      Ans.push_back(Sum);
    } else {
      long long Best = 0;
      for(int L = 1; L <= MaxV; L++){
        long long QLimit = min(Cap - 1, (long long)(MaxV / L));
        long long S1 = 0;
        for(long long Q = 1; Q <= QLimit; Q++){
          long long Lo = Q * (long long)L;
          if(Lo > MaxV) break;
          long long Hi = min((Q + 1) * (long long)L - 1, (long long)MaxV);
          long long C = Pref[Hi] - Pref[Lo - 1];
          S1 += Q * C;
        }
        long long Idx = Cap * (long long)L;
        long long C2 = 0, B = 0;
        if(Idx <= MaxV){
          C2 = (long long)N - Pref[Idx - 1];
          B = Count[Idx];
        }
        long long Tot = S1 + (Cap - 1) * C2 + B;
        if(Tot > Best) Best = Tot;
      }
      Ans.push_back(Best);
    }
    for(size_t i = 0; i < Ans.size(); i++)
      cout << Ans[i] << (i + 1 == Ans.size() ? '\n' : ' ');
  }
  return 0;
}
