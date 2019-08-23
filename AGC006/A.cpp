#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s,t;
    cin >> n >> s >> t;
    int p = 0;
    for(int i = 1; i <= n; i++) if(s.substr(n-i) == t.substr(0,i)) p = i;
    cout << 2 * n - p << endl;
}
