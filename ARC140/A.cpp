#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>

using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int need(int len, string s){
	int n = s.size();
	int m = n / len;
	assert(n % len == 0);
	vector<string> vs(m);
	for(int i = 0; i < m; i++){
		vs[i] = s.substr(i * len, len);
	}

	int cnt = 0;
	for(int i = 0; i < len; i++){
		map<char, int> mp;
		for(string x: vs){
			mp[x[i]]++;
		}
		int mx = -1;
		for(auto p: mp) mx = max(mx, p.second);
		cnt += (m - mx);
	}
	return cnt;
}

int main(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;

	int ans = n;
	for(int len = 1; len <= n/2; len++){
		if(n % len != 0) continue;
		int m = need(len, s);
		if(m <= k) ans = min(ans, len);
	}

	cout << ans << endl;
}
