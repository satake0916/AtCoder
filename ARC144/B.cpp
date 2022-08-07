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

int n,a,b;
vector<int> A;

bool isOK(int target){
	ll cnt = 0;
	for(int x: A){
		if(x < target){
			cnt -= (target - x + a - 1) / a;
		}else{
			cnt += (x - target) / b;
		}
	}
	return cnt >= 0;
}

int main(){
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		A.pb(t);
	}

	int l = 1, r = 1e9+1;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(isOK(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}

	cout << l << endl;
}
