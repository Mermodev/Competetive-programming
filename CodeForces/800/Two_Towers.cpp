#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int Q, N, M;
    string S1, S2;
    cin >> Q;
    while(Q--){
        int err = 0;
        cin >> N >> M;
        cin >> S1 >> S2;
        for(int i = 1; i < N; i++)
            if(S1[i] == S1[i-1])
                err++;
        for(int i = 1; i < M; i++)
            if(S2[i] == S2[i-1])
                err++;
        if(err == 0)
            cout << "YES\n";
        else if(err > 1)
            cout << "NO\n";
        else if (S1[N-1] == S2[M-1])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}