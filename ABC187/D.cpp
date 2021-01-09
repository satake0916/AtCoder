#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> v;
    long long def = 0;
    for(int i = 0; i < n; i++){
        long long a,b;
        cin >> a >> b;
        def -= a;
        v.push_back(2*a + b);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        def += v[i];
        ans++;
        if(def > 0){
            break;
        }
    }

    cout << ans << endl;
}
