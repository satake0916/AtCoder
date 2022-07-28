#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,q;
	cin >> n >> q;
	ll x[n], y[n];
	rep(i, 0, n) cin >> x[i] >> y[i];

	ll mnx = numeric_limits<ll>::max(), mny = numeric_limits<ll>::max();
	ll mxx = numeric_limits<ll>::min(), mxy = numeric_limits<ll>::min();

	rep(i, 0, n){
		ll nxtx = x[i] + y[i];
		ll nxty = y[i] - x[i];
		x[i] = nxtx;
		y[i] = nxty;

		mnx = min(mnx, x[i]);
		mny = min(mny, y[i]);
		mxx = max(mxx, x[i]);
		mxy = max(mxy, y[i]);
	}

	rep(i, 0, q){
		int t;
		cin >> t;
		t--;
		ll a = abs(x[t] - mnx);
		ll b = abs(x[t] - mxx);
		ll c = abs(y[t] - mny);
		ll d = abs(y[t] - mxy);
		cout << max(max(max(a,b), c), d) << endl;
	}
}
