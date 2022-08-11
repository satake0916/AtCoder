#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int main(){
	int n;
	cin >> n;
	vector<long double> p(n);
	for(auto &x: p) cin >> x;

	vector<vector<long double>> dp(n, vector<long double>(n+1, 0));

	dp[0][0] = 1 - p[0];
	dp[0][1] = p[0];

	for(int i = 0; i < n-1; i++){
		for(int j = 0; j <= n; j++){
			if(dp[i][j] == 0) continue;
			dp[i+1][j] += dp[i][j] * (1-p[i+1]);
			dp[i+1][j+1] += dp[i][j] * p[i+1];
		}
	}

	long double ans = 0;
	for(int i = n/2 + 1; i <= n; i++){
		ans += dp[n-1][i];
	}

	cout << fixed << setprecision(10) << ans << endl;
}
