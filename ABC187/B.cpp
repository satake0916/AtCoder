#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double t = ((double)y[i]-y[j]) / (x[i]-x[j]) ;
            if(-1 <= t && t <= 1) ans++;
        }
    }

    cout << ans << endl;
}
