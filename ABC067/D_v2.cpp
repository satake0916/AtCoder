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

const int MAX = 100000;
int dis[2][MAX];
vector<vector<int>> g(MAX);

void dfs(int now, int pre, int d, int f){
	dis[f][now] = d;
	for(int x: g[now]){
		if(x == pre) continue;
		dfs(x, now, d+1, f);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x,y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(0, -1, 0, 0);
	dfs(n-1, -1, 0, 1);

	int b_cnt = 0, w_cnt = 0;
	for(int i = 0; i < n; i++){
		if(dis[0][i] <= dis[1][i]) b_cnt++;
		else w_cnt++;
	}

	cout << (b_cnt > w_cnt ? "Fennec" : "Snuke") << endl;
}
