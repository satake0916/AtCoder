#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> v;
	rep(i, 0, n){
		int a,b;
		cin >> a >> b;
		v.pb(b);
		v.pb(a-b);
	}

	ll ans = 0;
	sort(v.rbegin(), v.rend());

	rep(i, 0, k){
		ans += v[i];
	}

	cout << ans << endl;
}
