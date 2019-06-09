#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    a.push_back(n+1);
    COMinit();
    ll ans = 1;
    ll now = 0;
    for(int i = 0; i < a.size(); i++){
        ll dif = a[i] - now - 1;
        ll way = 0;
        for(int j = 0; 2 * j <= dif; j++){
            way += COM(dif - j, j);
            way = (way + MOD) % MOD;
        }
        ans *= way;
        ans =  (ans + MOD) % MOD;
        now = a[i] + 1;
    }
    cout << ans << endl;
}
