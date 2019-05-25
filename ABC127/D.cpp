#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n), b(m), c(m);
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i = 0; i < m; i++){
        cin >> b[i] >> c[i];
        mp[c[i]] += b[i];
    }
    ll ans = 0;
    auto itr = mp.end();
    while(1){
        itr--;
        if(n > itr->second){
            n -= itr->second;
            ans += itr->second * itr->first;
        }else{
            ans += itr->first * n;
            break;
        }
    }
    cout << ans << endl;
}
