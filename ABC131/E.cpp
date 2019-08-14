#include "bits/stdc++.h"
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int s = (n-1) * (n-2) / 2;
    if(k > s){
        cout << -1 << endl;
        return 0;
    }
    int m = n - 1;
    m += s-k;
    cout << m << endl;
    for(int i = 1; i < n; i++){
        cout << i << " " << n << endl;
    }
    int count = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(count >= s-k){
                return 0;
            }else{
                cout << i << " " << j << endl;
                count++;
            }
        }
    }
}
