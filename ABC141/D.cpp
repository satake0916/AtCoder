#include "bits/stdc++.h"
using namespace std;
 
int main() {
    int n,m;
    cin >> n >> m;
    long long sum = 0;
    priority_queue<int> q;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
        sum += a;
    }
    for(int i = 0; i < m; i++){
        int t = q.top();
        q.pop();
        int s = t / 2;
        sum -= (t-s);
        q.push(s);
    }
    cout << sum << endl;
}
