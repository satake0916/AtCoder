#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    ll r,d,x;
    cin >>  r >> d >> x;
    for(int i = 0; i < 10; i++){
        x = r * x - d;
        cout << x << endl;
    }
}
