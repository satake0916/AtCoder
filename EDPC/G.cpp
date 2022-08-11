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

vector<int> flag, dp;
vector<vector<int>> g;

int f(int x){
	if(flag[x]) return dp[x];
	flag[x] = 1;
	int ret = 0;
	for(int nxt: g[x]){
		ret = max(ret, f(nxt) + 1);
	}
	return dp[x] = ret;
}

int main(){
	int n,m;
	cin >> n >> m;
	flag.resize(n), dp.resize(n), g.resize(n);
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, f(i));
	}

	cout << ans << endl;
}
