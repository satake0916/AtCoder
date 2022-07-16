#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n;
	cin >> n;
	int a[n];
	const int MAX = 2*100000;
	ll sum[MAX+1];
	for(int i = 0; i < MAX+1; i++) sum[i] = 0;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		a[i] = t;
		sum[t]++;
	}
	
	for(int i = 0; i < MAX; i++){
		sum[i+1] += sum[i];
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		int t = a[i];
		ans += sum[t-1] * (n-sum[t]);
	}

	cout << ans << endl;
}
