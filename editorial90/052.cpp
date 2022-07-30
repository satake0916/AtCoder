#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	ll n;
	cin >> n;
	const int MOD = 1e9+7;
	ll ans = 1;
	rep(i, 0, n){
		ll t = 0;
		rep(j, 0, 6){
			ll a;
			cin >> a;
			t += a;
		}
		ans *= t;
		ans %= MOD;
	}

	cout << ans << endl;
}
