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
	int n,k;
	cin >> n >> k;
	vector<int> h(n), dp(n, numeric_limits<int>::max());
	for(auto &x: h) cin >> x;
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= k; j++){
			if(i+j < n) dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
		}
	}

	cout << dp[n-1] << endl;
}
