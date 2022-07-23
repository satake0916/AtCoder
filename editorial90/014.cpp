#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];

	sort(all(a));
	sort(all(b));

	ll ans = 0;
	rep(i, 0, n) ans += abs(a[i] - b[i]);

	cout << ans << endl;

}
