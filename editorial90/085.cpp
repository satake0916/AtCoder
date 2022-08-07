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

vector<long long> yakusuu(ll x){
	vector<long long> ret;
	for(ll i = 1; i * i <= x; i++){
		if(x % i == 0){
			ret.pb(i);
			if(i != x / i) ret.pb(x / i);
		}
	}
	sort( ret.begin(), ret.end());
	return ret;
}

int main(){
	ll k;
	cin >> k;
	auto v = yakusuu(k);
	
	ll ans = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j = i; j < v.size(); j++){
			ll a = v[i], b = v[j];
			if((k/a) < b) continue;
			if(k % (a*b) != 0) continue;

			ll c = k / a / b;
			if(b > c) continue;
			ans++;
		}
	}

	cout << ans << endl;
}
