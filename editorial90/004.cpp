#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int h,w;
	cin >> h >> w;
	int a[h][w];
	rep(i,0,h){
		rep(j,0,w){
			cin >> a[i][j];
		}
	}

	int sum_h[h], sum_w[w];
	rep(i,0,h){
		int t = 0;
		rep(j,0,w) t += a[i][j];
		sum_h[i] = t;
	}
	rep(j,0,w){
		int t = 0;
		rep(i,0,h) t += a[i][j];
		sum_w[j] = t;
	}

	rep(i,0,h){
		rep(j,0,w){
			cout << sum_h[i] + sum_w[j] - a[i][j];
			if(j == w-1) cout << endl;
			else cout << " ";
		}
	}
}
