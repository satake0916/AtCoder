#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> alpha(26,0);
    ll ans = n * (n-1) / 2 + 1;
    for(int i = 0; i < n; i++){
        alpha[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        ans -= alpha[i] * (alpha[i] - 1) / 2;
    }
    cout << ans << endl;
}
