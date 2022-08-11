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
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<vector<int>> dp(n, vector<int>(3));
	dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
	for(int i = 1; i < n; i++){
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
	}

	cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}
