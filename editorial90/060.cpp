#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int main(){
	int n;
	cin >> n;
	int a[n];
	rep(i, 0, n) cin >> a[i];

	vector<int> sei(n, 1e6);
	int up[n];
	rep(i, 0, n){
		auto p = lower_bound(all(sei), a[i]);
		up[i] = p - sei.begin();
		up[i]++;
		*p = a[i];
	}

	int down[n];
	vector<int> gya(n, 1e6);
	for(int i = n-1; i >= 0; i--){
		auto p = lower_bound(all(gya), a[i]);
		down[i] = p - gya.begin();
		down[i]++;
		*p = a[i];
	}

	int ans = 0;
	rep(i, 0, n){
		ans = max(ans, up[i]+down[i]);
	}
	cout << ans-1 << endl;
}
