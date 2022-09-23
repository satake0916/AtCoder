#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n+1);
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == a[i]) cnt++;
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > i){
			if(a[a[i]] == i) ans++;
		}
	}

	cout << ans + cnt * (cnt - 1) / 2 << endl;
}
