#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(arg) print(#arg, arg)

template <class Tp> void print(string_view name, Tp arg) {
  cerr << "(debug) " <<  name << " = " << arg << endl;
}

template <class Tp> void print(string_view name, vector<Tp> arg) {
  cerr << "(debug) " << name << " = [ ";
  copy(cbegin(arg), cend(arg), ostream_iterator<Tp>(cerr, " "));
  cerr << "]" << endl;;
}

#else
#define debug(arg) true
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> edge(n);
	vector<ll> cost(n, 0);
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
		cost[u] += a[v];
		cost[v] += a[u];
	}

	debug(cost);

	vector<bool> exist(n, true);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	for(int i = 0; i < n; i++) q.push(make_pair(cost[i], i));

	ll ans = numeric_limits<ll>::min();
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		if(!exist[p.second]) continue;
		exist[p.second] = false;
		debug(p.second);
		debug(p.first);
		
		ans = max(ans, p.first);
		for(int nx: edge[p.second]){
			if(exist[nx]){
				cost[nx] -= a[p.second];
				q.push(make_pair(cost[nx], nx));
			}
		}
	}

	cout << ans << endl;
}
