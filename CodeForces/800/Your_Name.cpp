#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int Q, N;
    string S1, S2;
    cin >> Q;
    while(Q--){
        cin >> N;
        cin >> S1 >> S2;
        sort(S1.begin(), S1.end());
        sort(S2.begin(), S2.end());
        cout << ((S1 == S2) ? "YES\n" : "NO\n");
    }
}