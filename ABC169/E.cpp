#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int x,y;
    if(n % 2 == 0){
        x = a[n/2] + a[n/2 - 1];
        y = b[n/2] + b[n/2 - 1];
    }else{
        x = a[n/2];
        y = b[n/2];
    }
    cout << y - x + 1 << endl;
}
