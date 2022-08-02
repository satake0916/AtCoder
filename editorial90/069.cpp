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

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
	const int MOD = 1e9+7;
	ll n,k;
	cin >> n >> k;
	ll ans = k;
	if(n >= 2) (ans *= (k-1)) %= MOD;
	if(n >= 3) (ans *= modpow(k-2, n-2, MOD)) %= MOD;
	cout << ans << endl;
}
