#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s >> t;
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n,0));
    if(s[0] == t[0]) dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == t[0] || dp[i-1][0] == 1) dp[i][0] = 1;
        if(s[0] == t[i] || dp[0][i-1] == 1) dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1;
            dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i][j]);
        }
    }
    cout << dp[n-1][n-1] + 1 << endl;
}
