#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> rest(n+1,0);
    vector<int> ans(n+1,0);
    vector<int> res;
    for(int i = n; i > 0; i--){
        ans[i] = (abs(rest[i] - a[i]))%2;
        if(ans[i] == 1){
            res.push_back(i);
            for(int j = 1; j * j <= i; j++){
                if(i % j == 0){
                    if(j * j == i) rest[j]++;
                    else{
                        rest[j]++;
                        rest[i/j]++;
                    }
                }
            }
        }
    }
    int m = res.size();
    cout << m << endl;
    for(int i = 0; i < m; i++){
        cout << res[i];
        if(i == m-1) cout  << endl;
        else cout << " ";
    }
}
