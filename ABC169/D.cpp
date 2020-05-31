#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int method(ll n){
    int ans = 0;
    ll m = n;
    for(ll i = 2; i * i <= n; i++){
        int t = 0;
        while(m % i == 0){
            m /= i;
            t++;
        }
        for(int j = 1; j < 10000; j++){
            if(t >= j){
                ans++;
                t -= j;
            }else{
                break;
            }
        }
    }
    if(m != 1) ans++;
    return ans;
}

int main(){
    ll n;
    cin >> n; 
    cout << method(n) << endl; 
}
