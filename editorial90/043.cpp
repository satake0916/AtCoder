#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

struct state{
	int x, y, dir;
};

int main(){
	int h,w,sx,sy,gx,gy;
	cin >> h >> w >> sx >> sy >> gx >> gy;
	sx--, sy--, gx--, gy--;
	string s[h];
	rep(i, 0, h) cin >> s[i];

	const int inf = 1e9;
	int dis[h][w][4];
	rep(i, 0, h){
		rep(j, 0, w){
			rep(dir, 0, 4){
				dis[i][j][dir] = inf;
			}
		}
	}

	deque<state> deq;
	rep(i, 0, 4){
		dis[sx][sy][i] = 0;
		deq.pb({sx, sy, i});
	}

	const int dx[4] = {1, 0, -1, 0};
	const int dy[4] = {0, 1, 0, -1};

	while(!deq.empty()){
		state u = deq.front();
		deq.pop_front();

		rep(i, 0, 4){
			int tx = u.x + dx[i], ty = u.y + dy[i];
			int cost = dis[u.x][u.y][u.dir] + (u.dir != i ? 1 : 0);
			if(0 <= tx && tx < h && 0 <= ty && ty < w){
				if(s[tx][ty] == '.' && dis[tx][ty][i] > cost){
					dis[tx][ty][i] = cost;
					if(u.dir != i) deq.pb({tx, ty, i});
					else deq.push_front({tx, ty, i});
				}
			}
		}
	}

	int ans = inf;
	rep(i, 0, 4) ans = min(ans, dis[gx][gy][i]);

	cout << ans << endl;
}
