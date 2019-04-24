#include "bits/stdc++.h"
using namespace std;

const int n;
// (cst, to)
vector<vector<pair<int,int> > > g(n);
vector<bool> used(n,false);

int prim(){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > que;
    que.push(make_pair(0,0));
    int ret = 0;
    while(!que.empty()) {
        int cst = que.top().first, v = que.top().second;
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