#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

int n, a, b;
vl v;


long long combination(int n, int r)
{
    if(n < r)
        return 0;
    if(n-r < r)
        r = n-r;
    long long ret = 1;
    for(int i=0; i<r; i++){
        ret *= (n--);
        ret /= i+1;
    }
    return ret;
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n >> a >> b;
    v.resize(n);
    rep(i,n) cin >> v[i];

    sort(v.begin(), v.end(), greater<ll>());

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << setprecision(10);

    ll sum = 0;
    rep(i,a) sum += v[i];
    cout << sum / (double)a << endl;

    int num_max = 0;
    int num_min = 0;
    rep(i,n){
        if(v[i] == v[a-1]){
            num_max++;
            if(i < a) num_min++;
        }
    }

    ll ret = 0;

    if(v[0] != v[a-1]){
        ret += combination(num_max, num_min);
    }else{
        for(int i = a; i <= b; i++){
            ret += combination(num_max, i);
        }
    }

    cout << ret << endl;
    return 0;
    
}
