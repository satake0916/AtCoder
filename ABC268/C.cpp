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
	vector<int> p(n);
	for(int i = 0; i < n; i++) cin >> p[i];

	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int temp = p[i];
		int cond[3];
		cond[0] = temp - i - 1;
		cond[1] = temp - i;
		cond[2] = temp - i + 1;
		for(int j = 0; j < 3; j++){
			mp[(cond[j] + n) % n]++;
		}
	}

	int ans = 0;
	for(auto p: mp){
		ans = max(ans, p.second);
	}

	cout << ans << endl;
}
