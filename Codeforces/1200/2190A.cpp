#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    string S, Ans;
    cin >> S;
    Ans = S;
    sort(Ans.begin(), Ans.end());
    if(S == Ans)
      cout << "Bob\n";
    else{
      int ones = 0;
      for(auto&e : S)
        if(e == '1') ones++;
      vector<int> OutPos;
      for(int i = S.size() - 1; i > S.size() - 1 - ones; i--)
        if(S[i] == '0')
          OutPos.push_back(i + 1);
      int Cnt = OutPos.size();
      for(int i = 0; i < S.size(); i++){
        if(S[i] == '1'){
          Cnt--;
          OutPos.push_back(i + 1);
        }
        if(!Cnt)
          break;
      }
      sort(OutPos.begin(), OutPos.end());
      cout << "Alice\n" << OutPos.size() << '\n';
      for(auto&e : OutPos)
        cout << e << ' ';
      cout << '\n';
    }
  }
}
