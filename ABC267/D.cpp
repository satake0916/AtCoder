#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(arg) print(#arg, arg)

template <class Tp> void print(string_view name, Tp arg) {
  cerr << "(debug) " <<  name << " = " << arg << endl;
}

template <class Tp> void print(string_view name, vector<Tp> arg) {
  cerr << "(debug) " << name << " = [ ";
  copy(cbegin(arg), cend(arg), ostream_iterator<Tp>(cerr, " "));
  cerr << "]" << endl;;
}

#else
#define debug(arg) true
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin >> n >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<vector<ll>> dp(n+1, vector<long long>(m+1, numeric_limits<ll>::min() / 2));
	for(int i = 0; i < n+1; i++) dp[i][0] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i < j) continue;
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[i-1] * j);
		}
	}

	cout << dp[n][m] << endl;
}
