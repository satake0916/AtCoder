#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll n,m,k;
	cin >> n >> m >> k;
	ll now[m];
	ll next_temp[m+1];
	const int MOD = 998244353;
	for(int i = 0; i < m; i++){
		now[i] = 1;
	}
	ll sum_prev = m;
	for(int count = 1; count < n; count++){
		//数列のcount番目の値を決定したときの場合の数
		for(int i = 0; i < m+1; i++){
			next_temp[i] = 0;
		}
		for(ll i = 0; i < m; i++){
			ll il = max((ll)0, min(i, i-(k-1)));
			ll ir = min(m, i+k);
			next_temp[il] -= now[i];
			(next_temp[il] += MOD) %= MOD;
			next_temp[ir] += now[i];
			next_temp[ir] %= MOD;
			//(next_temp[max((ll)0, i-k)] += now[i]) %= MOD;
			//(next_temp[min(m, i+k+1)] += MOD - now[i]) %= MOD;
		}
		
		ll t = sum_prev;
		sum_prev = 0;
		for(int i = 0; i <m; i++){
			t += next_temp[i];
			t %= MOD;
			next_temp[i] = t;
			sum_prev += t;
			sum_prev %= MOD;
		}

		for(int i = 0; i < m; i++){
			now[i] = next_temp[i];
		}
	}

	cout << sum_prev << endl;
}
