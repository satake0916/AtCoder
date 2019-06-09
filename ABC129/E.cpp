#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int MOD = 1000000007;

int main() {
    string l;
    cin >> l;
    int n = l.size();
    ll room = 1;
    ll zero = 2;
    for(int i = 1; i < n; i++){
        if(l[i] == '0'){
            room *= 3;
            zero *= 1;
        }else{
            room = 3 * room + zero * 1;
            zero = zero * 2;
        }
        room %= MOD;
        zero %= MOD;
    }
    cout << (room + zero) % MOD << endl;
}
