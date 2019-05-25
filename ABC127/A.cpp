#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    int a,b;
    cin >> a >> b;
    if(a <= 5) b = 0;
    else if(a <= 12) b /= 2;
    cout << b << endl;
}
