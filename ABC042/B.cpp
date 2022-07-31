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
	int n,l;
	cin >> n >> l;
	vector<string> v;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v.pb(s);
	}
	sort(v.begin(), v.end());
	string ans = "";
	for(int i = 0; i < n; i++){
		ans += v[i];
	}
	cout << ans << endl;
}
