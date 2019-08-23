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
	string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[i+1]){
            int t = max(i+1, n-i-1);
            if(t < ans) ans = t;
        }
    }
    cout << ans << endl;
}
