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
    int n,d;
    cin >> n >> d;
    vi r(n);
    rep(i,n) cin >> r[i];
    ll ans = 0;
    sort(r.begin(), r.end());
    int right = 2;   
    for (int left = 0; left < n-2; ++left) {
        if(r[right] - r[left] <= d){
            while (right < n-1 && r[right+1] - r[left] <= d) {
                ++right;
            }
            ll t = right - left;
            ans += t * (t - 1) / 2;
        }

        if(right < n && right - left <= 2) ++right;
    }
    cout << ans << endl;
}
