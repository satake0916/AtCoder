#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	ll a[n];
	rep(i, 0, n) cin >> a[i];

	vector<vector<ll> > dp(n, vector<ll>(2));

	dp[0][1] = a[0];
	dp[0][0] = numeric_limits<ll>::max() / 2;

	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = a[i] + min(dp[i-1][0], dp[i-1][1]);
	}

	ll ans = min(dp[n-1][0], dp[n-1][1]);


	dp[0][1] = numeric_limits<ll>::max() / 2;
	dp[0][0] = 0;

	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i-1][1];
		dp[i][1] = a[i] + min(dp[i-1][0], dp[i-1][1]);
	}

	ans = min(ans, dp[n-1][1]);

	cout << ans << endl;
}
