#include<bits/stdc++.h>
using namespace std;

#define LL long long 
#define ssize(x) (LL)(x.size())

pair<char, char> GetFirstChars(vector<int> V){
  pair<char, char> Out = {',',','};
  for(int i = 0; i < ssize(V); i++){
    if(Out.first == ',' && V[i])
      Out.first = char('A' + i);
    else if(Out.first != ',' && Out.second == ',' && V[i]){
      Out.second = char('A' + i);
      return Out;
    }
  }
  return Out;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  string S, Out = "";
  cin >> S;
  vector<int> V(26);
  for(auto&e : S)
    V[e - 'A']++;
  pair<char, char> FirstTwo = GetFirstChars(V);
  char PrevCharacter = '.';
  for(int i = 0; i < ssize(S); i++){
    int RemCharacters = ssize(S) - i;
    bool Skip = false;
    for(int p = 0; p < 26; p++){
      if(RemCharacters % 2 && (RemCharacters / 2 + 1) == V[p]){
        if(PrevCharacter == char('A' + p)){
          cout << -1 << '\n';
          return 0;
        }
        Out.push_back(char('A' + p));
        PrevCharacter = char('A' + p);
        Skip = true;
        V[p]--;
        break;
      }
    }
    if(Skip)
      continue;
    if(PrevCharacter != FirstTwo.first){
      Out.push_back(FirstTwo.first);
      PrevCharacter = FirstTwo.first;
      V[FirstTwo.first - 'A']--;
    }
    else if(FirstTwo.second == ','){
      cout << -1 << '\n';
      return 0;
    }
    else if(PrevCharacter != FirstTwo.second){
      Out.push_back(FirstTwo.second);
      PrevCharacter = FirstTwo.second;
      V[FirstTwo.second - 'A']--;
    }
    if(V[FirstTwo.first - 'A'] == 0 || V[FirstTwo.second - 'A'] == 0)
      FirstTwo = GetFirstChars(V);
  }
  for(int i = 1; i < ssize(Out); i++)
    if(Out[i] == Out[i-1]){
      cout << -1 << '\n';
      return 0;
    }
  cout << Out << '\n';
}
