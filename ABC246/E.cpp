#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	ax--, ay--, bx--, by--;

	vector<string> board(n);
	for(int i = 0; i < n; i++) cin >> board[i];

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, numeric_limits<int>::max() / 2)));
	for(int i = 0; i < 4; i++){
		dp[ax][ay][i] = 1;
	}

	queue<array<int, 3>> q;
	for(int i = 0; i < 4; i++) q.push({ax, ay, i});

	const int dx[4] = {-1, 1, -1, 1};
	const int dy[4] = {-1, -1, 1, 1};

	while(!q.empty()){
		auto p = q.front();
		q.pop();

		int x = p[0], y = p[1], d = p[2];

		for(int i = 0; i < 4; i++){
			if(i != d){
				dp[x][y][i] = min(dp[x][y][i], dp[x][y][d] + 1);
			}
		}

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == '.'){
				if(d == i){
					if(dp[nx][ny][i] > dp[x][y][d]){
						dp[nx][ny][i] = dp[x][y][d];
						q.push({nx, ny, i});
					}
				}else{
					if(dp[nx][ny][i] > dp[x][y][d] + 1){
						dp[nx][ny][i] = dp[x][y][d] + 1;
						q.push({nx, ny, i});
					}
				}
			}
		}
	}

	int ans = numeric_limits<int>::max() / 2;
	for(int i = 0; i < 4; i++){
		ans = min(ans, dp[bx][by][i]);
	}

	if(ans == numeric_limits<int>::max() / 2) cout << -1 << endl;
	else cout << ans << endl;
}
