#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> sum(n+1,0);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        sum[a]++;
        sum[b+1]--;
    }
    for(int i = 1; i < n; i++){
        sum[i] += sum[i-1];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(sum[i] == m) ans++;
        //cout << sum[i] << " ";
    }
    cout << ans << endl;
}
