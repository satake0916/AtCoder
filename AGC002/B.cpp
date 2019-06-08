#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n,l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = -1;
    vector<int> ret;
    for(int i = 0; i < n-1; i++){
        if(a[i] + a[i+1] >= l){
            ans = i+1;
            break;
        }
    }
    if(ans == -1){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;
        for(int i = ans; i < n; i++){
            ret.push_back(i);
        }
        for(int i = ans - 1; i > 0; i--){
            ret.push_back(i);
        }
        reverse(ret.begin(), ret.end());
        for(int i = 0; i < n-1; i++){
            cout << ret[i] << endl;
        }
    }
}
