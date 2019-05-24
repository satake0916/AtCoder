#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<vector<int> > area(h, vector<int>(w, -1));
    queue<pair<int,int> > q;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char a;
            cin >> a;
            if(a == '#'){
                area[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }
    int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 4; i++){
            int tx = x + dx[i], ty = y + dy[i];
            if(tx < 0 || ty < 0 || tx >= h || ty >= w || area[tx][ty] >= 0) continue;
            area[tx][ty] = area[x][y] + 1;
            q.push(make_pair(tx,ty));
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans = max(ans, area[i][j]);
        }
    }
    cout << ans << endl;
}
