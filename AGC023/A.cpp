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
    cin >> n;
    vector<ll> sum(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(i == 0) sum[i] = a;
        else sum[i] = sum[i-1] + a;
    }

    map<ll, ll> mp;
    mp[0]++;
    for(int i = 0; i < n; i++) mp[sum[i]]++;
    
    ll ans = 0;
    for(auto p : mp) ans += p.second * (p.second - 1) / 2;

    cout << ans << endl;
}
