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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b > a){
            cout << "No" << '\n';
            continue;
        }
        if(b > d){
            cout << "No" << '\n';
            continue;
        }
        if(c >= b){
            cout << "Yes" << '\n';
            continue;
        }
        ll g = gcd(b,d);
        if(c < b - g + a%g){
            cout << "No" << '\n';
        }else{
            cout << "Yes" << '\n';
        }
    }
}
