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

ll rev(ll k){
	ll ret = 0;
	while(k > 0){
		ret *= 10;
		ret += k % 10;
		k /= 10;
	}
	return ret;
}

ll f(ll x){
	ll mn = x;
	ll nxt = rev(x);
	while(mn != nxt){
		mn = min(mn, nxt);
		nxt = rev(nxt);
	}
	return mn;
}

int main(){
	ll n,k;
	cin >> n >> k;
	if(k%10 == 0){
		cout << (n == k) << endl;
		return 0;
	}
	ll rk = rev(k);
	ll nk = k;
	set<ll> st;
	while(nk <= n){
		if(f(nk) == k) st.insert(nk);
		nk *= 10;
	}
	while(rk <= n){
		if(f(rk) == k) st.insert(rk);
		rk *= 10;
	}

	cout << st.size() << endl;
}
