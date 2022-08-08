#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int main(){
	ll n;
	cin >> n;
	int ans = 0;
	
	const int MAX = 1000000;
	bool dp[MAX];
	for(int i = 0; i < MAX; i++) dp[i] = false;
	dp[0] = dp[1] = true;
	vector<int> primes;

	for(ll q = 2; q*q*q < n; q++){
		if(dp[q]) continue;
		ans += upper_bound( primes.begin(), primes.end(), n / (q*q*q)) - primes.begin();
		primes.pb(q);
		for(ll j = q*2; j*j*j < n; j+=q){
			dp[j] = true;
		}
	}

	cout << ans << endl;
}
