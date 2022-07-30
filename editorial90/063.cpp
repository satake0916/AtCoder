#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int main(){
	int h,w;
	cin >> h >> w;
	int p[h][w];
	rep(i, 0, h){
		rep(j, 0, w){
			cin >> p[i][j];
		}
	}

	int ans = 0;
	for(int bit = 0; bit < (1 << h); bit++){
		int digit = 0;
		rep(i, 0, h){
			if(bit & (1 << i)) digit++;
		}

		map<int, int> mp;
		for(int j = 0; j < w; j++){
			int t = -1;
			bool f = true;
			for(int i = 0; i < h; i++){
				if(bit & (1 << i)){
					if(t == -1){
						t = p[i][j];
					}else{
						if(t != p[i][j]) f = false;
					}
				}
			}
			if(f) mp[t]++;
		}

		int mx = 0;
		for(auto p: mp){
			mx = max(mx, p.second);
		}
		ans = max(ans, mx * digit);
	}

	cout << ans << endl;
}
