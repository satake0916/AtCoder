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
	vector<vector<ll>> dp(N+1, vector<ll>(N*1000+1, W+1));
	dp[0][0] = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N*1000+1; j++){
			if(dp[i][j] == W+1) continue;
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if(dp[i][j] + w[i] <= W) dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]], dp[i][j] + w[i]);
		}
	}

	ll ans = -1;
	for(int i = N*1000; i >= 0; i--){
		if(dp[N][i] <= W){
			ans = i;
			break;
		}
	}

	cout << ans << endl;
}
