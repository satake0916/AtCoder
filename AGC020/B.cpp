#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int k;
    cin >> k;
    vector<ll> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    ll min_n = 2, max_n = 2;
    for(int i = k-1; i >= 0; i--){
        ll min_num = ((min_n + a[i] - 1) / a[i]) * a[i];
        ll max_num = (max_n / a[i]) * a[i] + a[i] - 1;
        if(min_num > max_n || max_num < min_n){
            cout << -1 << endl;
            return 0;
        }
        min_n = min_num;
        max_n = max_num;
    }
    cout << min_n << " " << max_n << endl;
}
