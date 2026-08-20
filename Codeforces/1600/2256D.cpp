#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

long long modpow(long long base, long long exp) {
    base %= MOD;
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

long long binomial(long long n, long long k) {
    if (n < 0 || k < 0) return (n == 0 && k == 0) ? 1 : 0; 
    if (k > n) return 0;
    k = min(k, n - k);
    long long res = 1;
    for (long long i = 1; i <= k; ++i) {
        res = res * (n - k + i) % MOD;
        res = res * modpow(i, MOD - 2) % MOD;
    }
    return res % MOD;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int Q;
  cin >> Q;
  while(Q--){
    int N;
    cin >> N;
    string S;
    cin >> S;
    long long WAmt = 0, BAmt = 0, WGrp = 0, BGrp = 0;
    if(S[0] == '0'){ BAmt++; BGrp++; }
    else { WAmt++; WGrp++; }
    for(int i = 1; i < N; i++){
      if(S[i] == '0'){
        BAmt++;
        if(S[i - 1] == '1') BGrp++;
      } else {
        WAmt++;
        if(S[i - 1] == '0') WGrp++;
      }
    }
    long long part0 = (BGrp == 0) ? 1 : binomial(BAmt - 1, BGrp - 1);
    long long part1 = (WGrp == 0) ? 1 : binomial(WAmt - 1, WGrp - 1);
    long long Ans = part0 * part1 % MOD;
    cout << Ans << '\n';
  }
}
