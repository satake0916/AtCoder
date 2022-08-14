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

int main(){
	int n,k;
	cin >> n >> k;
	vector<string> ss(n);
	for(auto &x: ss) cin >> x;

	int ans = -1;
	for(int bit = 0; bit < (1 << n); bit++){
		map<char, int> mp;
		for(int i = 0; i < n; i++){
			if((1 << i) & bit){
				for(char c: ss[i]){
					mp[c]++;
				}
			}
		}
		int cnt = 0;
		for(auto p: mp){
			if(p.second == k) cnt++;
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;
}
