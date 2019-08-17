#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n);
    for(int i = 0; i < n+1; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(b[i] > a[i]){
            b[i] -= a[i];
            sum += a[i];
            if(a[i+1] > b[i]){
                a[i+1] -= b[i];
                sum += b[i];
            }else{
                sum += a[i+1];
                a[i+1] = 0;
            }
        }else{
            sum += b[i];
        }
    }
    cout << sum << endl;
}
