#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll numonce = n * (n+1) / 2;
    if(sum % numonce != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll k = sum / numonce;
    vector<ll> dif(n);
    for(int i = 0; i < n-1; i++){
        dif[i] = a[i+1] - a[i];
    }
    dif[n-1] = a[0] - a[n-1];
    ll count = k;
    for(int i = 0; i < n; i++){
        dif[i] -= k;
        if(dif[i] < 0){
            if(dif[i] % n != 0){
                cout << "NO" << endl;
                return 0;
            }else{
                count += dif[i] / n;
            }
        }else if(dif[i] != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(count == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
