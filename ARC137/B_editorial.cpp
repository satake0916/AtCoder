#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0 ; i< n; i++) cin >> a[i];

	int mn = 0, mx = 0, cur = 0, x = 0, y = 0;
	for(int i = 0; i < n; i++){
		if(a[i]) cur++;
		else cur--;

		chmin(x, cur - mx);
		chmax(y, cur - mn);

		chmax(mx, cur);
		chmin(mn, cur);
	}
	cout << y - x + 1 << endl;
}
