#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	ll n;
	cin >> n;
	ll a,b,c;
	cin >> a >> b >> c;
	ll ans = 10000;
	rep(i, 0, 10000){
		rep(j, 0, 10000){
			ll res = n - a * i - b * j;
			if(res < 0) break;
			if(res % c == 0){
				ans = min(ans, i+j+res/c);
			}
		}
	}

	cout << ans << endl;

}
