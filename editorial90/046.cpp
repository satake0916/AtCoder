#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	ll mod[3][46];
	rep(i, 0, 46) rep(j, 0, 3) mod[j][i] = 0;

	rep(i, 0, 3){
		rep(j, 0, n){
			int t;
			cin >> t;
			mod[i][t%46]++;
		}
	}

	ll ans = 0;
	rep(i, 0, 46){
		rep(j, 0, 46){
			rep(k, 0, 46){
				if((i+j+k)%46 == 0){
					ans += mod[0][i] * mod[1][j] * mod[2][k];
				}
			}
		}
	}

	cout << ans << endl;
}
