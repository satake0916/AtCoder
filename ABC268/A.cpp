#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	set<int> st;
	st.insert(a);
	st.insert(b);
	st.insert(c);
	st.insert(d);
	st.insert(e);
	cout << st.size() << endl;
}
