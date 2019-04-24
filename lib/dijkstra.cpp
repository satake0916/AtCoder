#include "bits/stdc++.h"
using namespace std;
int INF = numeric_limits<int>::max() / 2;

vector<vector<pair<int, int> > > edge;//edge[i][j] firstがiからj番目のノード、secondがその重み
vector<int> d(100000,INF);

void dijkstra(int start){
    priority_queue<int, vector<int>, greater<int> > q;

    d[start] = 0;
    q.push(start);

    while(!q.empty()){
        int now = q.top();
        q.pop();
        for(int j = 0; j < edge[now].size(); j++){
            int next = edge[now][j].first;
            int nextd = d[now] + edge[now][j].second;
            if(nextd < d[next]){
                d[next] = nextd;
                q.push(next);
            }
        }
    }
}