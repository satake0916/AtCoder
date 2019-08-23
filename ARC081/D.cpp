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
    string s1, s2;
    cin >> n >> s1 >> s2;
    ll ans;
    bool last;
    int t;
    if(s1[0] == s2[0]){
        ans = 3;
        last = true;
        t = 1;
    }else{
        ans = 6;
        last = false;
        t = 2;
    }
    for(int i = t; i < n; i++){
        if(last){
            if(s1[i] == s2[i]){
                ans *= 2;
                last = true;
            }else{
                ans *= 2;
                i++;
                last = false;
            }
        }else{
            if(s1[i] == s2[i]){
                last = true;
            }else{
                ans *= 3;
                i++;
                last = false;
            }
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
