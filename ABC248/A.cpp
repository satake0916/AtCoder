#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int res = 45;
	string s;
	cin >> s;
	for(char c: s) res -= (c - '0');
	cout << res << endl;
}
