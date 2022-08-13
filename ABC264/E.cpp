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

class UnionFind
{
    std::vector<int> data;
	vector<bool> l;

  public:
    UnionFind(int size, int light) : data(size, -1), l(size, false) {
		for(int i = 0; i < size; i++){
			if(i >= size - light) l[i] = true;
		}
	}

    int unite(int x, int y)
    {
        x = root(x);
        y = root(y);
		int xsize = size(x);
		int ysize = size(y);
		bool xlight = l[x];
		bool ylight = l[y];
        if (x != y)
        {
            if (data[y] < data[x])
                std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
		int ret = 0;
		if(xlight && !ylight) ret = ysize;
		if(!xlight && ylight) ret = xsize;
		if(xlight || ylight) l[x] = true;
        return ret;
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

int main(){
	int n,m,e;
	cin >> n >> m >> e;
	vector<int> ans;
	vector<pair<int, int>> edge;
	for(int i = 0; i < e; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		edge.eb(u, v);
	}

	set<int> rest;
	for(int i = 0; i < e; i++) rest.insert(i);

	int q;
	cin >> q;
	vector<int> x(q);
	for(int i = 0; i < q; i++){
		cin >> x[i];
		x[i]--;
		rest.erase(x[i]);
	}


	UnionFind uf = UnionFind(n+m, m);
	int cnt = 0;
	for(int t: rest){
		cnt += uf.unite(edge[t].first, edge[t].second);
	}

	/*
	for(int i = 0; i < x.size(); i++){
		cout << x[i] << " ";
	}
	cout << endl;
	*/

	for(int i = q-1; i >= 0; i--){
		ans.pb(cnt);
		//cout << x[i] << endl;
		cnt += uf.unite(edge[x[i]].first, edge[x[i]].second);
	}

	for(int i = ans.size()-1; i >= 0; i--){
		cout << ans[i] << endl;
	}
}

