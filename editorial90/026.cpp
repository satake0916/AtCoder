#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

vector<vector<int> > g;
vector<int> col;

void dfs(int pos, int color){
	col[pos] = color;
	for(int nxt: g[pos]){
		if(col[nxt] <= 0) dfs(nxt, 3-color);
	}
}

int main(){
	int n;
	cin >> n;
	g.resize(n);
	col.resize(n);
	rep(i, 0, n-1){
		int a,b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(0, 1);
	vector<vector<int> > g(2);
	rep(i, 0, n){
		g[col[i]-1].pb(i);
	}

	int mx = 0;
	if(g[1].size() > g[0].size()) mx = 1;

	rep(i, 0, n/2){
		if(i) cout << " ";
		cout << g[mx][i]+1;
	}
	cout << endl;

}
