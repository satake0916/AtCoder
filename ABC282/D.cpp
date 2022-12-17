#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

vector<vector<int>> edge;
vector<int> nodes;

class UnionFind
{
    std::vector<int> data;

  public:
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y)
    {
        return root(x) == root(y);
    }
    int root(int x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    ll size(int x)
    {
        return -data[root(x)];
    }
};

bool nibu = true;

void color(ll &a, ll &b, int pre, int s){
	if(pre == nodes[s]){
		nibu = false;
		return;
	}
	if(nodes[s] != 0) return;
	nodes[s] = pre * -1;
	if(nodes[s] == 1) a++;
	if(nodes[s] == -1) b++;
	for(int x: edge[s]){
		color(a, b, nodes[s], x);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin >> n >> m;
	edge.resize(n);
	nodes.resize(n, 0);
	UnionFind uf(n);
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
		uf.unite(u, v);
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(nodes[i] == 0){
			ll a = 0, b = 0;
			color(a, b, 1, i);
			ans += a * b;
		}
	}

	if(!nibu){
		cout << 0 << endl;
	}else{
		ll temp = 0;
		for(int i = 0; i < n; i++){
			ll sz = uf.size(i);
			temp += n - sz;
		}
		cout << ans - m + temp / 2 << endl;
	}

}
