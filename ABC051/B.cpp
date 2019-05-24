#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k,s;
    cin >> k >> s;
    int ans = 0;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= k; j++){
            int t = s - i - j;
            if(0 <= t && t <= k) ans++;
        }
    }
    cout << ans << endl;
}
