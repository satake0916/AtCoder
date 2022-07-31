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

int main() {
    int a, b, c;
	cin >> a >> b >> c;
    bool ans = (a == 5 && b == 7 && c == 5) || (a == 7 && b == 5 && c == 5) || (a == 5 && b == 5 && c == 7);
	cout << (ans ? "YES" : "NO") << endl;
}
