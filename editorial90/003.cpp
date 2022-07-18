#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

vector<int> dijkstra(int start, vector<vector<array<int, 2> > > &edges){
	using P = pair<int ,int>;
    priority_queue<P, vector<P>, greater<P> > q;

	vector<int> d(edges.size(), 100000000);

    d[start] = 0;
    q.push(make_pair(start, 0));

    while(!q.empty()){
		auto p = q.top();
        q.pop();
		if(d[p.first] < p.second) continue;
		for(auto edge: edges[p.first]){
			int next = edge[0];
			int nextd = d[p.first] + edge[1];
			if(nextd < d[next]){
				d[next] = nextd;
				q.push(make_pair(next, d[next]));
			}
		}
	}

	return d;
}

int main(){
	int n;
	cin >> n;
	vector<vector<array<int, 2> > > edges(n);
	rep(i, 0, n-1){
		int a,b;
		cin >> a >> b;
		a--, b--;
		edges[a].pb({b, 1});
		edges[b].pb({a, 1});
	}
	auto vec = dijkstra(0, edges);
	int ind = 0;
	int mx = vec[0];
	rep(i, 0, vec.size()){
		if(vec[i] > mx){
			mx = vec[i];
			ind = i;
		}
	}

	auto r = dijkstra(ind, edges);
	mx = 0;
	for(int x: r){
		mx = max(mx, x);
	}

	cout << mx + 1 << endl;
}
