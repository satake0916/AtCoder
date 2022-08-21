#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    b.push_back(numeric_limits<int>::max());
    b.push_back(numeric_limits<int>::min());
    sort(b.begin(), b.end());

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int r = *it;
        ans = min(ans, abs(a[i] - r));
        int l = *prev(it);
        ans = min(ans, abs(a[i] - l));
    }

    cout << ans << endl;
}
