#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int t = l[i] + l[j];
            int p = lower_bound(l.begin(), l.end(), t) - l.begin();
            ans += p-j-1;
        }
    }
    cout << ans << endl;
}
