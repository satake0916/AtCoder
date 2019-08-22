#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > tasks;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        tasks.push_back(make_pair(a,b));
    }
    tasks.push_back(make_pair(m+1, 0));
    sort(tasks.begin(), tasks.end());
    vector<int> rewards(m+1,0);
    priority_queue<int> q;
    int index = 0;
    for(int i = 1; i <= m; i++){
            while(tasks[index].first <= i){
                q.push(tasks[index].second);
                index++;
            }
            if(!q.empty()){
                rewards[i] = q.top();
                q.pop();
            }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        ans += rewards[i];
    }
    cout << ans << endl;
}
