#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<vector<pair<ll,int> > > g;
vector<bool> used;

ll prim(){
    priority_queue<pair<ll,int>, vector<pair<ll,int> > > que;
    que.push(make_pair(0,0));
    ll ret = 0;
    while(!que.empty()) {
        ll cst = que.top().first, v = que.top().second;
        que.pop();
        if(used[v]) continue;
        used[v] = true;
        ret += cst;
        for(int i = 0; i < g[v].size(); i++){
            que.push(make_pair(g[v][i].first, g[v][i].second));
        }
    }
    return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n, false);
	vector<ll> a(n);
	for(auto &x: a) cin >> x;

 	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			ll cst =(modpow(a[i], a[j], m) + modpow(a[j], a[i], m)) % m;
			g[i].push_back(make_pair(cst, j));
			g[j].push_back(make_pair(cst, i));
		}
	}

	cout << prim() << endl;
}
