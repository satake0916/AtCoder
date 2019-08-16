#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int maxindex = -1, maxvalue = 0, nextvalue = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > maxvalue) maxindex = i,nextvalue = maxvalue,maxvalue = a[i];
        else if(a[i] > nextvalue) nextvalue = a[i];
    }
    for(int i = 0; i < n; i++){
        if(i == maxindex) cout << nextvalue << endl;
        else cout << maxvalue << endl;
    }
}
