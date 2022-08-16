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

const int MOD = 1e9+7;
int n;
vector<vector<int>> g;

vector<vector<int>> dp;
vector<vector<int>> flag;

ll f(int par, int x, int y){
	if(flag[x][y]) return dp[x][y];
	flag[x][y] = 1;
	ll ret = 1;
	for(int nxt: g[x]){
		if(nxt == par) continue;
		ll temp = f(x, nxt, 0);
		if(y == 0) (temp += f(x, nxt, 1)) %= MOD;
		(ret *= temp) %= MOD;
	}
	return dp[x][y] = ret;
}

int main(){
	cin >> n;
	g.resize(n);
	dp.resize(n, vector<int>(2));
	flag.resize(n, vector<int>(2));
	for(int i = 0; i < n-1; i++){
		int x,y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	ll ans = f(-1, 0, 0) + f(-1, 0, 1);
	ans %= MOD;

	cout << ans << endl;
}
