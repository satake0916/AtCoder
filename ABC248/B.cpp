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
	ll a,b,k;
	cin >> a >> b >> k;
	int ans = 0;
	while(a < b){
		a *= k;
		ans++;
	}

	cout << ans << endl;
}
