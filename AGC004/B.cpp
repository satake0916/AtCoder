#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll> > mins(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        mins[i][0] = a[i];
    }
    for(int start = 0; start < n; start++){
        for(int len = 1; len + start < n; len++){
            mins[start][len] = min(mins[start][len-1], a[start+len]);
        }
    }
    ll ans = LINF;
    for(int i = 0; i < n; i++){
        ll temp = x * i;
        for(int j = 0; j < n; j++){
            if(j - i >= 0) temp += mins[j-i][i];
            else temp += min(mins[0][j], mins[n + j - i][i - j - 1]);
        }
        //cout << temp << endl;
        ans = min(ans, temp);
    }
    cout << ans << endl;
}
