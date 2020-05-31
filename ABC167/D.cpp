#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }

    vector<bool> vb(n, false);
    vb[0] = true;
    int pos = 0;
    int loop = -1;
    while(true){
        int next = a[pos];
        if(vb[next]){
            loop = a[next];
            break;
        }
        vb[next] = true;
        pos = next;
    }

    int last = 0;
    for(ll i = 0; i < k; i++){
        if(last == loop){
            int c = 1;
            int d = a[last];
            while(d != loop){
                c++;
                d = a[d];
            }
            k -= ((k-i) / c) * c;
            if(i == k){
                cout << last + 1 << endl;
                return 0;
            }
        }
        last = a[last];
    }
    cout << last + 1 << endl;
}
