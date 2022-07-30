#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int button(int x){
	ll ret = x;
	while(x > 0){
		ret += x%10;
		x /= 10;
	}
	return ret % 100000;
}

int main(){
	ll n,k;
	cin >> n >> k;
	int vis[100000];
	rep(i, 0, 100000) vis[i] = -1;
	int off = -1;
	int loop = -1;
	int cnt = 0;
	while(vis[n] == -1){
		vis[n] = cnt;
		n = button(n);
		cnt++;
	}
	off = vis[n];
	loop = cnt - off;

	if(k > off) k = off + (k - off) % loop;
	int ans = -1;
	rep(i, 0, 100000){
		if(vis[i] == k) ans = i;
	}
	cout << ans << endl;
}
