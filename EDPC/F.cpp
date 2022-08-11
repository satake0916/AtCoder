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
	string s,t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n, vector<int>(m));
	if(s[0] == t[0]) dp[0][0] = 1;
	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i-1][0];
		if(s[i] == t[0]) dp[i][0] = 1;
	}
	for(int j = 1; j < m; j++){
		dp[0][j] = dp[0][j-1];
		if(s[0] == t[j]) dp[0][j] = 1;
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(s[i] == t[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int x = n-1, y = m-1;
	string ans = "";
	while(x >= 0 && y >= 0){
		if(x == 0){
			if(dp[0][y] > 0) ans = s[0] + ans;
			break;
		}
		if(y == 0){
			if(dp[x][0] > 0) ans = t[0] + ans;
			break;
		}
		if(dp[x-1][y-1] < dp[x][y] && dp[x-1][y] < dp[x][y] && dp[x][y-1] < dp[x][y]){
			ans = s[x] + ans;
			x--, y--;
		}else if(dp[x][y-1] == dp[x][y]){
			y--;
		}else{
			x--;
		}
	}

	cout << ans << endl;
}
