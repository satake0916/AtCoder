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
    int n, m;
    cin >> n >> m;
    int a[1000], b[1000], c[1000], dist[100][100];
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--,b[i]--;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    for(int i = 0; i < m; ++i){
        dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
        dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
    }
    
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int ans = m;
    
    for(int i = 0; i < m; ++i){
        bool shortest = false;
        for(int j = 0; j < n; ++j) if(dist[j][a[i]] + c[i] == dist[j][b[i]]) shortest = true;
        if(shortest) ans--;
    }
    
    cout << ans << endl;
    return 0;
}
