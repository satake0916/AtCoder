#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = numeric_limits<int>::max() / 2;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

vector<int> dijkstra(int start, vector<vector<array<int, 2> > >& edges){
	using P = pair<int ,int>;
    priority_queue<P, vector<P>, greater<P> > q;

	vector<int> d(edges.size(), INF);

    d[start] = 0;
    q.emplace(0, start);

    while(!q.empty()){
		auto p = q.top();
        q.pop();
		if(d[p.second] < p.first) continue;
		for(auto edge: edges[p.second]){
			int next = edge[0];
			int nextd = d[p.second] + edge[1];
			if(nextd < d[next]){
				d[next] = nextd;
				q.emplace(d[next], next);
			}
		}
	}

	return d;
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<array<int, 2> > > edges(n);
	rep(i, 0, m){
		int a,b,c;
		cin >> a >> b >> c;
		a--, b--;
		edges[a].pb({b, c});
		edges[b].pb({a, c});
	}

	const auto& v1 = dijkstra(0, edges);
	const auto& vn = dijkstra(n-1, edges);

	rep(i, 0, n){
		cout << v1[i] + vn[i] << endl;
	}
}
