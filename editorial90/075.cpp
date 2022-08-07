#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int split(ll x) {
    ll y = x;
    int ret = 0;
    for (ll i = 2; i * i <= y; i++) {
        while (x % i == 0) {
            x /= i;
            ret++;
        }
    }
    if (x != 1) ret++;
    return ret;
}

int main() {
    ll n;
    cin >> n;
    int sum = split(n);
    int ans = 0;
    for (int i = 0; i <= 32; i++) {
        if ((1 << i) >= sum) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
