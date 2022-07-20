#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	vector<vector<int> > sum(2, vector<int>(n+1));
	rep(i, 1, n+1){
		int c, p;
		cin >> c >> p;
		c--;
		sum[c][i] = sum[c][i-1] + p;
		sum[1-c][i] = sum[1-c][i-1];
	}

	int q;
	cin >> q;
	rep(i, 0, q){
		int l,r;
		cin >> l >> r;
		cout << sum[0][r] - sum[0][l-1] << " " << sum[1][r] - sum[1][l-1] << endl;
	}
}
