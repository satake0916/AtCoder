#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,p,q;
	cin >> n >> p >> q;
	int a[n];
	rep(i, 0, n) cin >> a[i];

	int ans = 0;
	rep(i, 0, n){
		rep(j, i+1, n){
			rep(k, j+1, n){
				rep(l, k+1, n){
					rep(m, l+1, n){
						ll t = 1;
						(t *= a[i]) %= p;
						(t *= a[j]) %= p;
						(t *= a[k]) %= p;
						(t *= a[l]) %= p;
						(t *= a[m]) %= p;
						if(t == q) ans++;
					}
				}
			}
		}
	}

	cout << ans << endl;
}
