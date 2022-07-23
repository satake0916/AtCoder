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
	int MAX = 1000;
	vector<vector<int> > area(MAX+2, vector<int>(MAX+2));
	rep(i, 0, n){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		area[a][b]++;
		area[a][d]--;
		area[c][b]--;
		area[c][d]++;
	}

	rep(i, 0, MAX+1){
		rep(j, 1, MAX+1){
			area[i][j] += area[i][j-1];
		}
	}

	rep(j, 0, MAX+1){
		rep(i, 1, MAX+1){
			area[i][j] += area[i-1][j];
		}
	}

	vector<int> ans(n);
	rep(i, 0, MAX+1){
		rep(j, 0, MAX+1){
			if(area[i][j] > 0) ans[area[i][j] - 1]++;
		}
	}

	rep(i, 0, n){
		cout << ans[i] << endl;
	}

}
