#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int k;
	cin >> k;
	if(k%9 != 0){
		cout << 0 << endl;
		return 0;
	}

	vector<ll> dp(k+1);
	dp[0] = 1;
	for(int i = 1; i <= k; i++){
		int t = min(i, 9);
		for(int head = 1; head <= t; head++){
			dp[i] += dp[i - head];
			dp[i] %= MOD;
		}
	}

	cout << dp[k] << endl;
}
