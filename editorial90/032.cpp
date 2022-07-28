#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define makep make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	int a[n][n];
	rep(i, 0, n){
		rep(j, 0, n){
			int t;
			cin >> t;
			a[i][j] = t;
		}
	}

	int m;
	cin >> m;

	set<pair<int, int> > anti;
	rep(i, 0, m){
		int x,y;
		cin >> x >> y;
		x--, y--;
		anti.insert(makep(x, y));
		anti.insert(makep(y, x));
	}

	vector<int> player;
	rep(i, 0, n) player.pb(i);

	int ans = 1000000;
	do{
		bool f = false;
		rep(i, 0, player.size()-1){
			if(anti.count(makep(player[i], player[i+1]))) f = true;
		}
		if(f) continue;
		int cost = 0;
		rep(i, 0, player.size()) cost += a[player[i]][i];

		ans = min(ans, cost);
			
	}while(next_permutation(all(player)));

	if(ans == 1000000) ans = -1;
	cout << ans << endl;
}
