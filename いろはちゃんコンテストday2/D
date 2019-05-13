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


class UnionFind
{
    std::vector<int> data;

  public:
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y)
    {
        return root(x) == root(y);
    }
    int root(int x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    ll size(int x)
    {
        return -data[root(x)];
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<int, pair<int, pair<int,int> > > > v;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        v.push_back(make_pair(c, make_pair(i+1, make_pair(a,b))));
    }
    sort(all(v));
    reverse(all(v));
    vi ans;
    rep(i,m){
        auto p = v[i].second;
        int first = p.second.first, second = p.second.second;
        if(!uf.find(first, second)){
            uf.unite(first, second);
            ans.push_back(p.first);
        }
    }
    sort(all(ans));
    for(int i: ans) cout << i << '\n';

}
