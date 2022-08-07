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
	bool f = (s == "BA" || (s[0] == 'A' && s[n-1] == 'B'));
	cout << (!f ? "Yes" : "No") << endl;
}
