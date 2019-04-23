#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{
    int n,k;
    cin >> n >> k;
    vi l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end(), greater<int>());
    int ans = 0;
    rep(i,k) ans += l[i];
    cout << ans << endl;
}
