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
const int MOD = 1e9+7;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int main(){
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	vector<int> dp(1 << n);
	dp[0] = 1;
	for(int s = 1; s < (1 << n); s++){
		int i = __builtin_popcount(s);
		for(int j = 0; j < n; j++){
			if(((1 << j) & s) && a[i-1][j]){
				(dp[s] += dp[s^(1 << j)]) %= MOD;
			}
		}
	}

	cout << dp[(1 << n) - 1] << endl;
}
