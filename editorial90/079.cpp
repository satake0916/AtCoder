#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int main(){
	int h,w;
	cin >> h >> w;
	int area[2][h][w];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < h; j++){
			for(int k = 0; k < w; k++){
				cin >> area[i][j][k];
			}
		}
	}

	const int dx[4] = {0, 0, 1, 1};
	const int dy[4] = {0, 1, 0, 1};
	ll ans = 0;
	for(int i = 0; i < h-1; i++){
		for(int j = 0; j < w-1; j++){
			int gap = area[1][i][j] - area[0][i][j];
			ans += abs(gap);
			for(int k = 0; k < 4; k++){
				area[0][i+dx[k]][j+dy[k]] += gap;
			}
		}
	}

	bool f = true;
	for(int i = 0; i < h; i++){
		f = f && (area[0][i][w-1] == area[1][i][w-1]);
	}
	for(int j = 0; j < w; j++){
		f = f && (area[0][h-1][j] == area[1][h-1][j]);
	}

	cout << (f ? "Yes" : "No") << endl;
	if(f) cout << ans << endl;
}
