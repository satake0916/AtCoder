#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int n, k;
vector<int> d;

bool check(int x) {
    while (x > 0) {
        for (int i = 0; i < k; i++) {
            if (d[i] == (x % 10)) return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    cin >> n >> k;
    d.resize(k);
    for (int i = 0; i < k; i++) cin >> d[i];

    int ans;
    for (ans = n; ans < 1e9; ans++) {
        if (check(ans)) break;
    }

    cout << ans << endl;
}
