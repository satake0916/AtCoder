#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main(){
    int MOD = 1e9+7;
    ll n,k,ans;
    ans = 0;
    cin >> n >> k;
    for(ll i = k; i <= n+1; i++){
        ll mi = i * (i-1) / 2;
        ll ma = i * (n + n - i + 1) / 2;
        ll t = ma - mi + 1;
        (ans += t) %= MOD;
    }
    cout << ans << endl;
}
