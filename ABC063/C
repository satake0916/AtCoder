#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> s(n);
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> s[i], ans += s[i];
    sort(s.begin(), s.end());
    if(ans % 10 == 0){
        for(int i = 0; i < n; i++){
            if((ans - s[i]) % 10 != 0){
                cout << ans - s[i] << endl;
                return 0;
            }
        }
        ans = 0;
    }
    cout << ans << endl;
}
