#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > >edge(n);
    for(int i = 0; i < m; i++){
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        edge[l].push_back(make_pair(r, d));
        edge[r].push_back(make_pair(l, -d));
    }

    vector<int> d(n, INF);
    for(int s = 0; s < n ; s++){
        if(d[s] != INF) continue;
        queue<int> q;
        d[s] = 0;
        q.push(s);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto item : edge[v]){
                if(d[item.first] != INF){
                    if(d[item.first] != d[v] + item.second){
                        cout << "No" << endl;
                        return 0;
                    }
                }else{
                    d[item.first] = d[v] + item.second;
                    q.push(item.first);
                }
            }
        }
    }
    cout << "Yes" << endl;
}
