#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    ll ans = 1;
    int n;
    cin >> n;
    vector<ll> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(b[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        ll a = b[i];
        if(a > (ll)1e18 / ans){
            cout << -1 << endl;
            return 0;
        }
        ans *= a;
    }
    cout << ans << endl;
}
