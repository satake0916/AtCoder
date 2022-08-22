#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll a, ll b){
	return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll ans = 4 * (ll)1e18;
	for(ll a = 0; a <= 1000000; a++){
		ll l = -1;
		ll r = 1000000;
		while(r - l > 1){
			ll mid = (l + r) / 2;
			if(f(a, mid) >= n){
				r = mid;
			}else{
				l = mid;
			}
		}
		ans = min(ans, f(a, r));
	}

	cout << ans << endl;
}
