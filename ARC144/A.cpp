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
	cin >> n;
	int m = n*2;
	string ans = "";
	while(n >= 4){
		ans += '4';
		n -= 4;
	}
	if(n > 0) ans = char('0' + n ) + ans;

	cout << m << endl;
	cout << ans << endl;
}
