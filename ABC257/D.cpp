#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll prim(int start, vector<vector<pair<ll, int> > > &g){
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > que;
    que.push(make_pair(0,start));
    ll ret = 0;
	vector<bool> used(g.size());
    while(!que.empty()) {
        ll cst = que.top().first, v = que.top().second;
        que.pop();
        if(used[v]) continue;
        used[v] = true;
        ret = max(ret, cst);
        for(int i = 0; i < g[v].size(); i++){
            que.push(make_pair(g[v][i].first, g[v][i].second));
        }
    }
    return ret;
}

int main(){
	int n;
	cin >> n;
	ll x[n], y[n], p[n];
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> p[i];
	}

	vector<vector<pair<ll, int> > > g(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (i == j) continue;
			ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			g[i].push_back(make_pair((d+p[i]-1)/p[i], j));
		}
	}

	ll ans = numeric_limits<ll>::max()/2;
	for(int i = 0; i < n; i++){
		ans = min(ans, prim(i, g));
	}
	cout << ans << endl;
}
