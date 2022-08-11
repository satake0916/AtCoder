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
	vector<int> h(n);
	for(auto &x: h) cin >> x;
	vector<int> dp(n, numeric_limits<int>::max());
	dp[0] = 0;
	for(int i = 0; i < n-1; i++){
		if(i+1 < n) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
		if(i+2 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
	}
	cout << dp[n-1] << endl;
}
