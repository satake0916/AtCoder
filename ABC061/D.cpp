#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

int n,m;//nは頂点数、mは辺の数
vector<pair<int, int> > edge;//edge[i](first, second) i番目の辺はfirst->second
vector<ll> weight;//weight[i] i番目の辺の重み
vector<ll> d(1010,LINF);//各頂点の始点からの最短距離。INFで初期化してある
vector<bool> negative(1010,false);

bool bellmanford(int start){
    d[start] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            auto p = edge[j];
            if(d[p.second] > d[p.first] + weight[j]){
                d[p.second] = d[p.first] + weight[j];
            }
        }
    }

    return true;
}

bool boolbellmanford(int start){
    d[start] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            auto p = edge[j];
            if(d[p.first] == LINF) continue;
            if(d[p.second] > d[p.first] + weight[j]){
                d[p.second] = d[p.first] + weight[j];
                negative[p.second] = true;
            }
            if(negative[p.first]) negative[p.second] = true;
        }
    }
    return true;
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    edge.resize(m);
    weight.resize(m);
    rep(i,m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        edge[i] = make_pair(a,b);
        weight[i] = -c;
    }

    bellmanford(0);
    boolbellmanford(0);

    if(negative[n-1]) cout << "inf" << endl;
    else cout << -d[n-1] << endl;

    return 0;
}
