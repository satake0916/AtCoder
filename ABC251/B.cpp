#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,w;
	cin >> n >> w;
	int a[n+2];
	a[0] = a[1] = 0;
	rep(i, 2, n+2) cin >> a[i];
	vector<bool> f(w+1);

	rep(i, 0, n+2){
		rep(j, i+1, n+2){
			rep(k, j+1, n+2){
				int t = a[i]+ a[j]+ a[k];
				if(t <= w) f[t] = true;
			}
		}
	}

	int ans = 0;
	rep(i, 1, w+1) if(f[i]) ans++;
	cout << ans << endl;
}
