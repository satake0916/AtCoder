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
	int h,w;
	cin >> h >> w;
	const int MOD = 1e9+7;
	vector<string> area(h);
	vector<vector<int>> dp(h, vector<int>(w, 0));
	for(int i = 0; i < h; i++){
		cin >> area[i];
	}

	dp[0][0] = 1;
	for(int i = 1; i < h; i++){
		dp[i][0] = dp[i-1][0];
		if(area[i][0] == '#') dp[i][0] = 0;
	}
	for(int j = 1; j < w; j++){
		dp[0][j] = dp[0][j-1];
		if(area[0][j] == '#') dp[0][j] = 0;
	}

	for(int i = 1; i < h; i++){
		for(int j = 1; j < w; j++){
			if(area[i][j] == '#'){
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			dp[i][j] %= MOD;
		}
	}

	cout << dp[h-1][w-1] << endl;
}
