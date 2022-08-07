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

int main(){
	int n;
	cin >> n;
	ll sum = 0;
	vector<int> a(2*n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[n+i] = a[i];
		sum += a[i];
	}

	if(sum % 10 != 0){
		cout << "No" << endl;
		return 0;
	}

	vector<ll> wa(2*n);
	wa[0] = a[0];
	for(int i = 1; i < 2*n; i++) wa[i] = wa[i-1] + a[i];

	bool ans = false;
	for(int i = 0; i < n; i++){
		ll pre = 0;
		if(i > 0) pre = wa[i-1];

		ll tar = pre + (sum / 10);
		auto it = lower_bound( wa.begin(), wa.end(), tar);
		if(*it == tar){
			ans = true;
			break;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;
}
