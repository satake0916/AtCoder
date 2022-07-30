#include <bits/stdc++.h>
using namespace std;
using intl = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int main(){
	intl n,q;
	cin >> n >> q;
	intl a[n];
	rep(i, 0, n) cin >> a[i];
	vector<intl> dis(n-1);
	intl sum = 0;
	rep(i, 0, n-1){
		dis[i] = a[i+1] - a[i];
		sum += abs(dis[i]);
	}
	
	for(int count = 0; count < q; count++){
		intl l,r,v;
		cin >> l >> r >> v;
		l--, r--;
		if(l > 0){
			sum -= abs(dis[l-1]);
			dis[l-1] += v;
			sum += abs(dis[l-1]);
		}
		if(r < n-1){
			sum -= abs(dis[r]);
			dis[r] -= v;
			sum += abs(dis[r]);
		}

		cout << sum << endl;
	}
}
