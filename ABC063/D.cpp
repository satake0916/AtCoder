#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

ll n,a,b;
vector<ll> h;

// index が条件を満たすかどうか。主にここを書き換える。
bool isOK(ll t) {
    ll needed = 0;
    for(int i = 0; i < n; i++){
        ll res = h[i] - b * t;
        if(res > 0) needed += (res + a - b - 1) / (a - b);
    }
    if(needed <= t) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1。最終的にはぎりぎり満たさないやつになる。
    ll ok = 1000000000; // 「index = n-1」が条件を満たさないこともあるので、初期値はn。最終的にはぎりぎり満たすやつになる。

    /* ok と ng のどちらが大きいかわからないことを考慮するならabsをつける */
    while ((ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    h.resize(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    cout << binary_search() << endl;
}
