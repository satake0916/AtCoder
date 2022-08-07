#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector< int >> g(n);
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		sort( g[i].begin(), g[i].end());
		if(g[i].size() == 0) continue;
		if(g[i].size() == 1 && g[i][0] < i) ans++;
		if(g[i].size() >= 2 && g[i][0] < i && g[i][1] >= i) ans++;
	}

	cout << ans << endl;
}
