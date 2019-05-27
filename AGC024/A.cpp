#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;
    ll k;
    cin >> a >> b >> c >> k;
    int sum = a + b + c;
    ll kp = k / 2;
    a = kp * sum + a, b = kp * sum + b, c = kp * sum + c;
    if(k % 2 == 1){
        int ap = b + c;
        int bp = a + c;
        int cp = a + b;
        if(abs(ap - bp) > 1e18) cout << "Unfair" << endl;
        cout << ap - bp << endl;
    }else{
        cout << a - b << endl;
    }
}
