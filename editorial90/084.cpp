#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int main(){
	int n;
	string s;
	cin >> n >> s;

	ll ans = 0;
	map<char, int> mp;
	for(int l = 0, r = 0; l < n; l++){
		if(r < n){
			while((mp['o'] == 0 || mp['x'] == 0) && r < n){
				mp[s[r]]++;
				r += 1;
			}
			if(mp['o'] && mp['x']) ans += n - r + 1;
		}else{
			if(mp['o'] && mp['x']) ans++;
		}
		
		mp[s[l]]--;
	}

	cout << ans << endl;		
}
