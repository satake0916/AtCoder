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
    int n;
    cin >> n;
    int ans = 0;
    vector<bool> cb(n,false), ca(n,false);
    rep(i,n){
        string s;
        cin >> s;
        rep(j, s.size()-1){
            if(s[j] == 'A' && s[j+1] == 'B') ans++;
        }
        if(s[0] == 'B') cb[i] = true;
        if(s[s.size()-1] == 'A') ca[i] = true;
    }
    bool f = true;
    int cc = 0, cv = 0;
    rep(i,n){
        if(ca[i] != cb[i]) f = false;
        if(ca[i]) cc++;
        if(cb[i]) cv++;
    }
    if(f && min(cc,cv) != 0) ans += (min(cc, cv)-1);
    else ans += min(cc,cv);

    cout << ans << endl;
}
