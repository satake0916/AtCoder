#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n,k,x;
	cin >> n >> k >> x;
	vector<long long> a(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 0; i < n; i++){
		ll t = min(a[i] / x, k);
		a[i] -= t * x;
		k -= t;
	}

	sort(a.rbegin(), a.rend());
	for(int i = 0; i < n; i++){
		if(k > 0){
			a[i] = 0;
			k--;
		}
	}

	for(int i = 0; i < n; i++) sum += a[i];

	cout << sum << endl;
}
