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
	int n;
	cin >> n;
	vector<int> t(n), x(n), a(n);
	map<int, pair<int, int>> mp;
	for(int i = 0; i < n; i++){
		cin >> t[i] >> x[i] >> a[i];
		mp[t[i]] = make_pair(x[i], a[i]);
	}

	vector<vector<ll>> dp(100005, vector<ll>(5, -1));

	dp[0][0] = 0;
	for(int i = 0; i <= 100000; i++){
		for(int j = 0; j < 5; j++){
			if(dp[i][j] < 0) continue;
			if(mp.count(i)){
				auto p = mp[i];
				if(p.first == j){
					dp[i][j] += p.second;
				}
			}
			if(j != 0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]);
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j != 4) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
		}
	}

	ll ans = 0;
	for(int i = 0; i < 5; i++){
		ans = max(ans, dp[100000][i]);
	}

	cout << ans << endl;
			
}
