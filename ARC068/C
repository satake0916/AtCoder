#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x;
    cin >> x;
    ll ans = x / 11;
    ll rest = x % 11;
    ans *= 2;
    if(0 < rest && rest <= 6) ans++;
    else if(6 < rest)ans += 2;
    cout << ans << endl;
}
