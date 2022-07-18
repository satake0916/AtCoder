
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()


int pow_int(int x, int y){
	int ret = 1;
	while(y--) ret *= x;
	return ret;
}

int main(){
	int n,b,k;
	cin >> n >> b >> k;
	int c[k];
	rep(i, 0, k) cin >> c[i];
	int MOD = 1e9 + 7;

	//10 ** i mod B
	int ten[n+1];
	ten[0] = 1;
	for(int i = 0; i < n; i++) ten[i+1] = ten[i] * 10 % b;

	vector<vector<ll> > dp(n, vector<ll>(b, 0));
	for(int x: c){
		dp[0][x%b]++;
	}

	//rep(j, 0, b) cout << dp[0][j] << " ";
	//cout << endl;

	rep(i, 0, n-1){
		rep(j, 0, b){
			for(int x: c){
				//cout << "hoge";
				//cout << dp[i+1][(j + x * (int)pow(10, i+1)) % b ] << " " <<  dp[i][j] << endl;
				//cout << j << " " <<  x << " " << pow_int(10, i+1) << endl;
				(dp[i+1][(j + x * ten[i+1]) % b] += dp[i][j]) %= MOD;
			}
		}
		//rep(j, 0, b) cout << dp[i+1][j] << " ";
		//cout << endl;
	}

	cout << dp[n-1][0] << endl;

}
