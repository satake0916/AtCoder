#include "bits/stdc++.h"
using namespace std;
int INF = numeric_limits<int>::max() / 2;

vector<vector<pair<int, int> > > edge;//edge[i][j] firstがiからj番目のノード、secondがその重み

/*
 * int start: 始点
 * edges: 枝。edges[i][j]が頂点iから伸びるj番目の枝で、[0]が終点, [1]が重み
 *
 * return d: d[i]が頂点iの始点からの最短距離
 *
 */
vector<int> dijkstra(int start, vector<vector<array<int, 2> > > edges){
	using P = pair<int ,int>;
    priority_queue<P, vector<P>, greater<P> > q;

	vector<int> d(edges.size(), INF);

    d[start] = 0;
    q.push(make_pair(0, start));

    while(!q.empty()){
		auto p = q.top();
        q.pop();
		if(d[p.second] < p.first) continue;
		for(auto edge: edges[p.second]){
			int next = edge[0];
			int nextd = d[p.second] + edge[1];
			if(nextd < d[next]){
				d[next] = nextd;
				q.push(make_pair(d[next], next));
			}
		}
	}

	return d;
}

int main(){
	int n = 3;
	vector<vector<array<int, 2> > > edges(3);
	edges[0].push_back({1, 10});
	edges[0].push_back({2, 20});
	edges[1].push_back({0, 10});
	edges[1].push_back({2, 5});
	edges[2].push_back({0, 20});
	edges[2].push_back({1, 5});

	auto p = dijkstra(0, edges);
	for(int i = 0; i < n; i++){
		cout << "i: " << p[i] << endl;
	}
}
