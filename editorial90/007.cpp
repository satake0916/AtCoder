#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	a.pb(numeric_limits<int>::min());
	a.pb(numeric_limits<int>::max());
	sort(all(a));
	int q;
	cin >> q;
	rep(i, 0, q){
		int b;
		cin >> b;
		auto it = lower_bound(all(a), b);
		int r = *it;
		int l = *(--it);
		//cout << l << " " << r << endl;
		cout << min(abs(l - b), abs(r - b)) << endl;
	}
}
