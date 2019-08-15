#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> a;

int isOK(int key) {
    //減らすとき1, 増やす時0, できたとき-1
    int f = 1;
    vector<int> now = a;
    now[0] -= key, now[n-1] -= key;
    if(now[0] < 0 || now[n-1] < 0) return f;
    for(int i = 1; i < n; i++){
        now[i] -= now[i-1];
        if(now[i] < 0){
            if(i % 2 == 0) return 1;
            else return 0;
        }
    }
    if(now[n-1] == 0) return -1;
    return 0;
}

int binary_search() {
    int ng = -2;
    int ok = 1000000002;

    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        int res = isOK(mid);

        if (res == 1) ok = mid;
        else if(res == 0) ng = mid;
        else return mid;
    }
    return -1;
}

int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans(n, 0);
    int last = binary_search();
    ans[0] = last*2;
    for(int i = 1; i < n; i++){
        last = a[i-1] - last;
        ans[i] = last * 2;
    }
    for(int i = 0; i < n; i++){
        if(i != n-1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
}
