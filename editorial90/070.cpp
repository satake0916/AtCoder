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

int main(){
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

	sort( x.begin(), x.end());
	sort( y.begin(), y.end());

	ll midx = x[n/2], midy = y[n/2];

	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += abs(midx - x[i]);
		ans += abs(midy - y[i]);
	}

	cout << ans << endl;
}
