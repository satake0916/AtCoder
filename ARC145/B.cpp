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
	ll n,a,b;
	cin >> n >> a >> b;
	if(n < a){
		cout << 0 << endl;
		return 0;
	}
	if(a > b){
		cout << (n / a - 1) * b + min(n % a + 1, b) << endl;
	}else{
		cout << n - a + 1 << endl;
	}
}
