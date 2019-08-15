#include "bits/stdc++.h"
using namespace std;

int main() {
    long long l,r;
    int c = 2019;
    cin >> l >> r;
    if(l / c != r / c){
        cout << 0 << endl;
        return 0;
    }
    long long ans = c;
    for(long long i = l; i <= r; i++){
        for(long long j = i+1; j <= r; j++){
            ans = min(ans, i*j%c);
        }
    }
    cout << ans << endl;
}
