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
 
int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    int a[50],b[50],c[50];
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }

    int dp[n+1][500][500];

    rep(i,n+1){
        rep(j,500){
            rep(k,500){
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    rep(i,n){
        rep(aa,500){
            rep(bb,500){
                if(dp[i][aa][bb] != INF){
                    dp[i+1][aa][bb] = min(dp[i+1][aa][bb], dp[i][aa][bb]);
                    dp[i+1][aa+a[i]][bb+b[i]] = min(dp[i+1][aa+a[i]][bb+b[i]], dp[i][aa][bb] + c[i]);
                }
            }
        }
    }

    int ans = INF;

    for(int aa = 1; aa < 500; aa++){
        for(int bb = 1; bb < 500; bb++){
            if(aa * mb == bb * ma){
                ans = min(ans, dp[n][aa][bb]);
            }
        }
    }
    
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
