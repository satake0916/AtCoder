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
	ll n, m;
	cin >> n >> m;
	vector<long long> a(n);
	vector<long long> sum(n+1);
	sum[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum[i+1] = sum[i] + a[i];
	}

	ll temp = 0;
	for(ll i = 0; i < m; i++) temp += a[i] * (i+1);
	ll ans = temp;

	debug(temp);
	debug(sum);

	for(ll i = 1; i + m - 1 < n; i++){
		temp -= (sum[i+m-1] - sum[i-1]);
		temp += a[i+m-1] * m;
		ans = max(ans, temp);
	}

	cout << ans << endl;

}	
