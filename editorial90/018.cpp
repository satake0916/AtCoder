#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	long double t, l, x, y;
	int q;
	cin >> t;
	cin >> l >> x >> y;
	cin >> q;
	long double PI = 3.14159265358979;
	rep(i, 0, q){
		long double e;
		cin >> e;
		long double cx = 0;
		long double cy = -(l / 2.0) * sin(e / t * 2.0 * PI);
		long double cz = (l / 2.0) - (l / 2.0) * cos(e / t * 2.0 * PI);
		long double d1 = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
		long double d2 = cz;
		cout << fixed << setprecision(12) << atan2(d2, d1) * 180.0 / PI << endl;
	}
}
