#include<bits/stdc++.h>
using namespace std;

int Get_depth(int Num, map<int, int>&Depths){
  if(Num == 1)
    return 0;
  else if(Depths[Num] != 0)
    return Depths[Num];
  return Get_depth(((Num % 2) ? Num + 1 : Num / 2), Depths) + 1;
}

int main(){
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    vector<int> V(N);
    for(auto&e : V)
      cin >> e;
    map<int, int> Depths;
    sort(V.begin(), V.end());
    Depths[1] = 0;
    Depths[2] = 1; 
    int Common = V[0], Common_depth = Get_depth(Common, Depths);
    for(int i = 1; i < N; i++){
      int Curr = V[i], Curr_depth = Get_depth(Curr, Depths);
      while(Common_depth != Curr_depth){
        if(Common_depth > Curr_depth){
          (Common % 2) ? Common++ : Common >>= 1;
          Common_depth--;
        }
        else{
          (Curr % 2) ? Curr++ : Curr >>= 1;
          Curr_depth--;
        }
      }
      while(Common != Curr){
        (Common % 2) ? Common++ : Common >>= 1;
        (Curr % 2) ? Curr++ : Curr >>= 1;
        Common_depth--;
      }
    }
    long long Cost2 = INT_MAX;
    if(Common < 3){
      Cost2 = 0;
      vector<int> W = V;
      for(int i = 0; i < N; i++)
        while(W[i] != Common){
          (W[i] % 2) ? W[i]++ : W[i] >>= 1;
          Cost2++;
        }
      Common = (Common == 1) ? 2 : 1;
    }
    long long Cost1 = 0;
    for(int i = 0; i < N; i++)
      while(V[i] != Common){
        (V[i] % 2) ? V[i]++ : V[i] >>= 1;
        Cost1++;
      }
    cout << min(Cost1, Cost2) << '\n';
  }
}
