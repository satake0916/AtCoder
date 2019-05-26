#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll f(ll b, ll n){
    if(n < b) return n;
    else return f(b, n/b) + n%b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,s;
    cin >> n >> s;
    if(n == s){
        cout << n+1 << endl;
        return 0;
    }
    if(s > n){
        cout << -1 << endl;
        return 0;
    }
    for(ll i = 2; i * i <= n; i++){
        if(f(i, n) == s){
            cout << i << endl;
            return 0;
        }
    }
    
    ll ans = -1;
    for(ll i = 1; i * i < n; i++){
        if((n-s)%i != 0) continue;
        ll b = (n-s)/i + 1;
        if(f(b,n) == s){
            ans = b;
        }
    }
    cout << ans << endl;
}
