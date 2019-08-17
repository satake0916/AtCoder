#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int incorrect = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != i+1) incorrect++;
    }
    if(incorrect <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}
