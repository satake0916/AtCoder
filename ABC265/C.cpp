#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int h,w;
	cin >> h >> w;
	string g[h];
	for(int i = 0; i < h; i++) cin >> g[i];

	vector<vector<int>> used(h, vector<int>(w, 0));
	int x = 0, y = 0;

	while(1){
		if(used[x][y]){
			cout << -1 << endl;
			return 0;
		}
		used[x][y] = 1;
		if(g[x][y] == 'U' && x != 0) x--;
		else if(g[x][y] == 'D' && x != h-1) x++;
		else if(g[x][y] == 'L' && y != 0) y--;
		else if(g[x][y] == 'R' && y != w-1) y++;
		else{
			cout << x+1 << " " << y+1 << endl;
			return 0;
		}
	}
}

