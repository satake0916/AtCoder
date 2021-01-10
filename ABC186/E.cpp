#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template<typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template<typename T>
T extgcd(T a, T b, T& x, T& y){
    T g = a;
    x = 1;
    y = 0;
    if(b != 0){
        g = extgcd(b, a%b, y, x);
        y -= (a / b) * x;
    }
    return g;
}

int main(){
    int t;
    cin >> t;
    ll n[t],s[t],k[t];
    for(int i = 0; i < t; i++){
        cin >> n[i] >> s[i] >> k[i];
    }

    for(int i = 0; i < t; i++){
        ll g = gcd(n[i], gcd(s[i],k[i]));
        n[i] /= g; s[i] /= g; k[i] /= g;
        if(gcd(n[i], k[i]) == 1){
            ll x,y;
            extgcd(k[i],n[i],x,y);
            cout << ((x+n[i])%n[i] * (n[i]-s[i])) % n[i] << endl;
        }else{
            cout << -1 << endl;
        }
    }
}
