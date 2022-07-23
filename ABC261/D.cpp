#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n,m;
	cin >> n >> m;
	ll x[n];
	rep(i, 0, n) cin >> x[i];

	map<int, ll> mpp;
	rep(i, 0, m){
		int c,y;
		cin >> c >> y;
		mpp[c] = y;
	}

	vector<vector<ll> > dp(n+1, vector<ll>(n+1));

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			dp[i+1][0] = max(dp[i][j], dp[i+1][0]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + x[i] + mpp[j+1]);
		}
	}

	/*
	rep(i, 0, n+1){
		rep(j, 0, n+1){
			cout << dp[i][j] <<  " ";
		}
		cout << endl;
	}
	*/

	ll ans = 0;
	rep(i, 0, n+1){
		ans = max(ans, dp[n][i]);
	}

	cout << ans << endl;
}
