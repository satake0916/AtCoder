#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    int n,m;
    cin >> n >> m;
    int ans = 0;
    vector<int> k(m);
    vector<vector<int> > s(m,vector<int>(n,0));
    for(int i = 0; i < m; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++){
            int t;
            cin >> t;
            t--;
            s[i][t] = 1;
        }
    }
    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];
    for(int i = 0; i < (1 << n); i++){
        vector<int> temp(m,0);
        for(int j = 0; j < n; j++){
            if((1 << j) & i){
                for(int k = 0; k < m; k++){
                    if(s[k][j] == 1) temp[k]++;
                }
            }
        }
        bool f = true;
        for(int j = 0; j < m; j++){
            if(temp[j] % 2 == p[j]) continue;
            else f = false;
        }
        if(f) ans++;
    }
    cout << ans << endl;
}
