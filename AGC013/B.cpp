#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<bool> used(n,false);
    vector<vector<int> > edge(n);
    int start, end;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        start = a, end = b;
    }
    used[start] = true, used[end] = true;
    deque<int> dq;
    dq.push_back(start);
    dq.push_back(end);
    for(int cnt = 0; cnt < n; cnt++){
        bool met = true;
        for(int i : edge[start]){
            if(!used[i]){
                met = false;
                start = i;
                dq.push_front(start);
                used[start] = true;
                break;
            }
        }
        if(!met) continue;

        for(int i : edge[end]){
            if(!used[i]){
                met = false;
                end = i;
                dq.push_back(end);
                used[end] = true;
                break;
            }
        }

    }
    cout << dq.size() << endl;
    while(!dq.empty()){
        cout << dq.front() + 1;
        dq.pop_front();
        if(!dq.empty()) cout << " ";
    }
    cout << endl;
}
