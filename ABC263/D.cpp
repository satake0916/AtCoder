#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(arg) print(#arg, arg)

template <class Tp> void print(string_view name, Tp arg) {
  cerr << "(debug) " <<  name << " = " << arg << endl;
}

template <class Tp> void print(string_view name, vector<Tp> arg) {
  cerr << "(debug) " << name << " = [ ";
  copy(cbegin(arg), cend(arg), ostream_iterator<Tp>(cerr, " "));
  cerr << "]" << endl;;
}

#else
#define debug(arg) true
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,l,r;
	cin >> n >> l >> r;
	vector<long long> a(n);
	for(auto &x: a) cin >> x;

	vector<long long> wa(n), gwa(n);
	wa[0] = min(a[0], l);
	for(int i = 1; i < n; i++){
		wa[i] = wa[i-1] + a[i];
		wa[i] = min(wa[i], l * (i+1));
	}
	gwa[n-1] = min(a[n-1], r);
	for(int i = n-2; i >= 0; i--){
		gwa[i] = a[i] + gwa[i+1];
		gwa[i] = min(gwa[i], r * (n-i));
	}

	ll ans = min(wa[n-1], gwa[0]);
	for(int i = 0; i < n-1; i++){
		ans = min(ans, wa[i] + gwa[i+1]);
	}

	cout << ans << endl;
}
