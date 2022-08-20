#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n,m,k;
	cin >> n >> m >> k;
	ll a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	ll ans = 0;
	for(ll bit = 31; bit >= 0; bit--){
		ll x = ans + (1LL << bit);

		vector<ll> fix;
		for(int i = 0; i < n; i++){
			ll need = 0;
			ll ai = a[i];
			for(int j = 31; j >= 0; j--){
				if(x & (1LL << j)){
					if(ai & (1LL << j)){
						continue;
					}else{
						ll mask = (1LL << (j+1)) - 1;
						ll temp = ai & mask;
						need += (1LL << j) - temp;
						ai += (1LL << j) - temp;
						assert(ai & (1LL << j));
					}
				}else{
					;
				}
			}
			fix.push_back(need);
		}
		sort(fix.begin(), fix.end());
		ll sum = 0;
		for(int i = 0; i < k; i++) sum += fix[i];
		if(sum <= m) ans = x;
	}

	cout << ans << endl;
}
