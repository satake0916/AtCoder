#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int MOD = 1e9+7;
	string t = "atcoder";
	int n;
	cin>> n;
	string s;
	cin >> s;
	int m = t.size();
	vector<vector<ll> > dp(n+1, vector<ll>(m+1));
	rep(i, 0, n+1) dp[i][0] = 1;
	rep(i, 1, n+1){
		rep(j, 1, m+1){
			dp[i][j] = dp[i-1][j];
			if(s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
			dp[i][j] %= MOD;
		}
	}

	cout << dp[n][m] << endl;
}
