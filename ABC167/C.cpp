#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 1e7;
    for(int bit = 1; bit < (1 << n); bit++){
        int temp = 0;
        vector<int> v(m, 0);
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                temp += c[i];
                for(int j = 0; j < m; j++){
                    v[j] += a[i][j];
                }
            }
        }

        bool f = true;
        for(int j = 0; j < m; j++){
            if(v[j] < x) f = false;
        }
        if(f) ans = min(ans, temp);
    }

    if(ans >= 1e7){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}
