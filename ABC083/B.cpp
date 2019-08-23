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
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n,a,b;
    int ans = 0;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        int t = i;
        int ret = 0;
        while(t != 0){
            ret += t%10;
            t /= 10;
        }
        if(ret >= a && ret <= b) ans += i;
    }
    cout << ans << endl;
}
