#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt(ll n, int nd, int digit){
	ll ret = 0;

	for(int i = digit; i <= nd; i++){
		ll low = 1;
		for(int j = 0; j < i-digit; j++){
			low *= 10;
			low++;
		}
		for(int j = 0; j < digit-1; j++) low *= 10;

		ll high = 1;
		for(int j = 0; j < i-digit; j++){
			high *= 10;
			high++;
		}
		for(int j = 0; j < digit-1; j++){
			high *= 10;
			high += 9;
		}
		
		ret += max(0LL, min(high, n) - low + 1);
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
	ll ans = 0;
	int nd = 0;
	ll temp = n;
	while(temp > 0){
		nd++;
		temp /= 10;
	}

	for(int i = 1; i <= nd; i++) ans += cnt(n, nd, i);

	cout << ans << endl;
}
