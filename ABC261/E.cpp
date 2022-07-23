#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int intpow(int x){
	int ret = 1;
	rep(i, 0, x) ret *= 2;
	return ret;
}

int main(){
	int n,c;
	cin >> n >> c;
	int t[n], a[n];
	rep(i, 0, n) cin >> t[i] >> a[i];

	vector<vector<vector<int>>> res(30, vector<vector<int>>(2, vector<int>(n+1)));

	rep(i, 0, 30){
		res[i][0][0] = 0;
		res[i][1][0] = 1;
	}

	rep(i, 0, 30){
		rep(j, 0, 2){
			rep(k, 1, n+1){
				int treat = t[k-1];
				int num = a[k-1];
				if(treat == 1){
					res[i][j][k] = res[i][j][k-1] & ((num >> i) & 1);
				}else if(treat == 2){
					res[i][j][k] = res[i][j][k-1] | ((num >> i) & 1);
				}else{
					res[i][j][k] = res[i][j][k-1] ^ ((num >> i) & 1);
				}
			}
		}
	}

	rep(i, 0, n){
		int temp = 0;
		rep(j, 0, 30){
			temp += intpow(j) * res[j][(c >> j) & 1][i+1];
		}
		c = temp;
		cout << c << endl;
	}
}
