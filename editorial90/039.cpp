#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int n;
vector<vector<int> > g;
vector<int> num;

void dfs(int pos, int par){
	num[pos] = 1;
	for(int x: g[pos]){
		if(x == par) continue;
		dfs(x, pos);
		num[pos] += num[x];
	}
}

int main(){
	cin >> n;
	g.resize(n);
	num.resize(n);
	int aa[n-1], bb[n-1];
	rep(i, 0, n-1){
		int a,b;
		cin >> a >> b;
		a--, b--;
		aa[i] = a;
		bb[i] = b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, -1);
	ll ans = 0;
	rep(i, 0, n-1){
		ll r = min(num[aa[i]], num[bb[i]]);
		ans += r * (n-r);
	}
	cout << ans << endl;
}
