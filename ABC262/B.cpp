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
	int n,m;
	cin >> n >> m;
	set<pair<int, int>> st;
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		u--, v--;
		st.insert(make_pair(u, v));
		st.insert(make_pair(v, u));
	}

	int ans = 0;
	for(int a = 0; a < n; a++){
		for(int b = a+1; b < n; b++){
			for(int c = b+1; c < n; c++){
				if(st.count(make_pair(a, b)) > 0 && st.count(make_pair(a, c)) > 0 && st.count(make_pair(b, c)) > 0){
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
}
