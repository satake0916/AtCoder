#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n,m;
	cin >> n >> m;
	int s[n-1], x[m];
	for(int i = 0; i < n-1; i++) cin >> s[i];
	for(int i = 0; i < m; i++) cin >> x[i];

	ll b[n];
	b[0] = 0;
	for(int i = 1; i < n; i++){
		b[i] = s[i-1] - b[i-1];
	}

	map<ll, int> mp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ll z = x[j] - b[i];
			if(i%2 != 0) z *= -1;
			mp[z]++;
		}
	}

	int ans = 0;
	for(auto p: mp){
		ans = max(ans, p.second);
	}

	cout << ans << endl;
}
