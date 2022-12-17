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
	vector<string> strs(n);
	for(int i = 0; i < n; i++){
		cin >> strs[i];
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			bool f = true;
			for(int k = 0; k < m; k++){
				if(strs[i][k] == 'x' && strs[j][k] == 'x') f = false;
			}
			if(f) ans++;
		}
	}
	
	cout << ans << endl;
}
