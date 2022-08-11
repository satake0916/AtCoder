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
	int N,W;
	cin >> N >> W;
	vector<int> w(N), v(N);
	for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
	vector<vector<ll>> dp(N+1, vector<ll>(W+1, -1));
	dp[0][0] = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= W; j++){
			if(dp[i][j] != -1){
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				if(j+w[i] <= W) dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
			}
		}
	}

	ll ans = -1;
	for(int i = 0; i <= W; i++) ans = max(ans, dp[N][i]);

	cout << ans << endl;
}
