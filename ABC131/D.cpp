#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > tasks;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        tasks.push_back(make_pair(b,a));
    }
    sort(tasks.begin(), tasks.end());
    int done = 0;
    bool able = true;
    for(int i = 0; i < n; i++){
        done += tasks[i].second;
        if(done > tasks[i].first) able = false;
    }
    cout << (able ? "Yes" : "No") << endl;
}
