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
    vector<int> q(n);
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        p--;
        q[p] = i;
    }
    int ma = 1;
    int last = q[0];
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(last < q[i]){
            last = q[i];
            ans++;
        }else{
            ma = max(ma, ans);
            last = q[i];
            ans = 1;
        }
    }
    ma = max(ma, ans);
    cout << n - ma << endl;
}
