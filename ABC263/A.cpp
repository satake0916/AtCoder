#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(arg) print(#arg, arg)

template <class Tp> void print(string_view name, Tp arg) { cerr << "(debug) " << name << " = " << arg << endl; }

template <class Tp> void print(string_view name, vector<Tp> arg) {
    cerr << "(debug) " << name << " = [ ";
    copy(cbegin(arg), cend(arg), ostream_iterator<Tp>(cerr, " "));
    cerr << "]" << endl;
    ;
}

#else
#define debug(arg) true
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	vector<int> a(5);
	for(int i = 0; i < 5; i++) cin >> a[i];
	sort(a.begin(), a.end());
	bool f = (a[0] == a[1] && a[1] == a[2]) && (a[3] == a[4]);
	bool g = (a[0] == a[1]) && (a[2] == a[3] && a[3] == a[4]);
	cout << ((f || g) ? "Yes" : "No") << endl;
}
