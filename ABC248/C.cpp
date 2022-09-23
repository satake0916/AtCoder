#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;

	const int MOD = 998244353;
	vector<vector<ll>> dp(n+1, vector<long long>(k+1));
	dp[0][0] = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			for(int nxt = 1; nxt <= m; nxt++){
				if(j+nxt <= k) (dp[i+1][j+nxt] += dp[i][j]) %= MOD;
			}
		}
	}

	ll ans = 0;
	for(int i = 0; i <= k; i++) (ans += dp[n][i]) %= MOD;

	cout << ans << endl;
}
