#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main(){
    ll n;
    ll ans = -1;
    cin >> n;
    vector<pair<ll, ll> > v(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v[i] = make_pair(a, i);
    }
    sort(v.rbegin(), v.rend());
    ll dp[n+1][n+1];
    dp[0][0] = 0;
    for(ll i = 0; i < n; i++){
        dp[i+1][0] = dp[i][0] + v[i].first * abs(v[i].second - i);
        dp[0][i+1] = dp[0][i] + v[i].first * abs(n-1-i - v[i].second);
    }
    for(ll i = 1; i < n; i++){
        for(ll j = 1; j < n; j++){
            if(i + j > n) continue;
            dp[i][j] = max(dp[i-1][j] + v[i+j-1].first * abs(v[i+j-1].second - i + 1), dp[i][j-1] + v[i+j-1].first * abs(n-1-j+1-v[i+j-1].second));

        }
    }
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp[i][n-i]);
    }
    cout << ans << endl;
}
