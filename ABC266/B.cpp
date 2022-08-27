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
	const int t = 998244353;
	ll n;
	cin >> n;
	ll a = n / t;
	ll b = n - a * t;
	if(b < 0) b += t;
	cout << b << endl;
}
