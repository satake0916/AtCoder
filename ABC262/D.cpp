#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

const int MOD = 998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;
	for(int m = 1; m <= n; m++){
		// m個選ぶ世界
		ll dp[n+1][n+1][m];
		// i個めまで見たときにj個選んでmod mがkの個数
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int k = 0; k < m; k++){
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][0][0] = 1;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < m; k++){
					(dp[i+1][j][k] += dp[i][j][k]) %= MOD;
					(dp[i+1][j+1][(k+a[i]) % m] += dp[i][j][k]) %= MOD;
				}
			}
		}

		debug(dp[n][m][0]);
		ans += dp[n][m][0];
		ans %= MOD;
	}

	cout << ans << endl;
}
