#include "bits/stdc++.h"
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        ans[a] = i;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i]+1;
        if(i == n-1) cout << endl;
        else cout << " ";
    }
}
