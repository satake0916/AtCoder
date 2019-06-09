#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> w[i];
        sum += w[i];
    }
    int ans = 1000000;
    int last = 0;
    for(int i = 0; i < n; i++){
        last += w[i];
        ans = min(ans, abs(sum - 2 * last));
    }
    cout << ans << endl;
}
