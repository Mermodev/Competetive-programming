#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N, Curr, Ans = 0;
    long long Pref = 0;
    cin >> N;
    set<long long> Prefs;
    Prefs.insert(0);
    while(N--){
      cin >> Curr;
      Pref += Curr;
      if(Prefs.find(Pref) != Prefs.end()){
        Prefs.clear();
        Prefs.insert(0);
        Pref = 0;
        Ans++;
      }
      else 
        Prefs.insert(Pref);
    }
    cout << Ans << '\n';
  }
}
