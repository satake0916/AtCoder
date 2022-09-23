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
	map<int, vector<int>> mp;
	for(int i = 1; i < n+1; i++){
		int t;
		cin >> t;
		mp[t].push_back(i);
	}

	int q;
	cin >> q;
	while(q--){
		int l,r,x;
		cin >> l >> r >> x;
		int ans = lower_bound(mp[x].begin(), mp[x].end(), r+1) - lower_bound(mp[x].begin(), mp[x].end(), l);
		cout << ans << endl;
	}
}
