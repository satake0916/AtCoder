#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> count(n,0);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        count[a]++;
        count[b]++;
    }
    bool f = true;
    for(int i = 0; i < n; i++) if(count[i] % 2 != 0) f = false;
    cout << (f ? "YES" : "NO") << endl;
}
