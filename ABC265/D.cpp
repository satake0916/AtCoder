#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n,p,q,r;
	cin >> n >> p >> q >> r;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<ll> prof(n+1);
	prof[0] = 0;
	for(int i = 0; i < n; i++) prof[i+1] = prof[i] + a[i];

	for(int x = 1; x <= n; x++){
		auto yit = lower_bound(prof.begin(), prof.end(), prof[x-1] + p);
		if(*yit != prof[x-1] + p) continue;
		int y = yit - prof.begin();
		y++;

		auto zit = lower_bound(prof.begin(), prof.end(), prof[y-1] + q);
		if(*zit != prof[y-1] + q) continue;
		int z = zit - prof.begin();
		z++;

		auto wit = lower_bound(prof.begin(), prof.end(), prof[z-1] + r);
		if(*wit != prof[z-1] + r) continue;
		
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;
	
}

