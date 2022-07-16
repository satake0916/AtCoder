#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll INF = numeric_limits<ll>::max() / 2;

vector<int> dijkstra(int start, vector<vector<array<int, 3> > > &edge){
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;

	vector<ll> d(edge.size(), INF);
	vector<int> ind(edge.size());

    d[start] = 0;
    q.push(make_pair(0, start));

    while(!q.empty()){
        auto pa = q.top();
		int now = pa.second;
		ll dis = pa.first;
        q.pop();
		if(d[now] != dis) continue;
		for(auto arr: edge[now]){
			int next = arr[0];
			ll nextd = d[now] + arr[1];
			if(d[next] > nextd){
				d[next] = nextd;
				ind[next] = arr[2];
				q.push(make_pair(d[next], next));
			}
        }
    }
	return ind;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<vector<array<int, 3> > > edge(n);
	
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		edge[a-1].push_back({b-1, c, i});
		edge[b-1].push_back({a-1, c, i});
	}
	auto ind = dijkstra(0, edge);

	for(int i = 1; i < n; i++){
		cout << ind[i]+1 << " ";
	}
	cout << endl;
}

