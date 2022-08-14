#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>

using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int strn(ll x){
	int ret = 0;
	while(x > 0){
		ret++;
		x /= 10;
	}
	return ret;
}

ll hig(int size, ll n){
	if(strn(n) % size != 0) return 0;
	ll mod = 1;
	for(int i = 0; i < size; i++) mod *= 10;
	vector<ll> cond;
	ll m = n;
	while(m > 0){
		cond.pb(m % mod);
		m /= mod;
	}
	ll top = cond[cond.size()-1], sec = cond[cond.size()-2];
	bool ok = false;
	bool mid = true;
	for(int i = cond.size()-2; i >= 0; i--){
		if(top < cond[i]){
			ok = true;
			break;
		}
		if(top != cond[i]){
			mid = false;
			break;
		}
	}
	if(!(ok || mid)) top--;

	if(top == 1){
		ll mn = 0;
		for(int i = 0; i < strn(n); i++) mn *= 10, mn++;
		if(n < mn) return 0;
	}

	ll ret = 0;
	for(int i = 0; i < cond.size(); i++){
		ret *= mod;
		ret += top;
	}

	return ret;
}

void solve(){
	ll n;
	cin >> n;
	int nsize = strn(n);
	ll ans = 1;
	for(int i = 0; i < nsize-1; i++) ans *= 10;
	ans--;

	for(int msize = 1; msize * 2 <= nsize; msize++){
		ans = max(ans, hig(msize, n));
	}
	cout << ans << endl;
}

int main(){
	int T; cin >> T;
	while(T--) solve();
}
