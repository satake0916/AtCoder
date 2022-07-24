#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int w,n;
	cin >> w >> n;
	vector<int> height(w);
	rep(i, 0, n){
		int l,r;
		cin >> l >> r;
		int mx = 0;
		rep(j, l, r+1){
			mx = max(mx, height[j]);
		}
		int nxt = mx+1;
		rep(j, l, r+1){
			height[j] = nxt;
		}
		cout << nxt << endl;
	}
}
