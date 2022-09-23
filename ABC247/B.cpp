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
	int n;
	cin >> n;
	map<string, int> mp;
	string ss[n], tt[n];
	for(int i = 0; i < n; i++){
		string s,t;
		cin >> s >> t;
		ss[i] = s, tt[i] = t;
		mp[s]++;
		if(s != t) mp[t]++;
	}

	bool f = true;
	for(int i = 0; i < n; i++){
		if(mp[ss[i]] > 1 && mp[tt[i]] > 1) f = false;
	}

	cout << (f ? "Yes" : "No") << endl;
}
