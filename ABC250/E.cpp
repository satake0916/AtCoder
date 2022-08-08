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
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	int q;
	cin >> q;

	set<int> sa, sb;
	vector<int> asize(1,0), bsize(1,0);
	for(int i = 0; i < n; i++){
		sa.insert(a[i]);
		sb.insert(b[i]);

		asize.pb(sa.size());
		bsize.pb(sb.size());
	}

	set<int> d;
	vector<int> ok;
	ok.pb(1);

	for(int i = 1; i <= n; i++){
		int ind = lower_bound( asize.begin(), asize.end(), i) - asize.begin() - 1;
		if(ind >= a.size()) break;
		if(d.find(a[ind]) == d.end()) d.insert(a[ind]);
		else d.erase(a[ind]);

		ind = lower_bound( bsize.begin(), bsize.end(), i) - bsize.begin() - 1;
		if(ind >= b.size()) break;
		if(d.find(b[ind]) == d.end()) d.insert(b[ind]);
		else d.erase(b[ind]);

		ok.pb(d.empty());
	}

	while(q--){
		int l,r;
		cin >> l >> r;
		if(asize[l] == bsize[r] && ok[asize[l]]){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}
