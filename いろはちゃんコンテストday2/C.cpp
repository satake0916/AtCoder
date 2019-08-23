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
    vi h(n);
    rep(i,n) cin >> h[i];
    vi hp = h;
    sort(all(hp));
    int count = 1;
    map<int,int> mp;
    rep(i,n){
        if(mp[hp[i]] == 0){
            mp[hp[i]] = count;
            count++;
        }
    }
    rep(i,n) cout << mp[h[i]] << '\n';
}
