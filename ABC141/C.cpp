#include "bits/stdc++.h"
using namespace std;
 
int main() {
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> count(n, -q+k-1);
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        t--;
        count[t]++;
    }
    for(int i = 0; i < n; i++){
        cout << (count[i] >= 0 ? "Yes" : "No") << endl;
    }
}
