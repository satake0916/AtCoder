#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int h,w;
    vector<vector<char> > s(55, vector<char>(55, '#'));
    vector<vector<int> > area(55, vector<int>(55, -1));
    cin >> h >> w;
    int white = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> s[i][j];
            if(s[i][j] == '.') white++;
        }
    }
    queue<pair<int, int> > q;
    q.push(make_pair(1,1));
    area[1][1] = 1;
    int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
    int shotestpath = -1;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p.first == h && p.second == w){
            shotestpath = area[p.first][p.second];
            break;
        }
        for(int i = 0; i < 4; i++){
            int nextx = p.first + dx[i], nexty = p.second + dy[i];
            if(s[nextx][nexty] == '.' && area[nextx][nexty] == -1){
                area[nextx][nexty] = area[p.first][p.second] + 1;
                q.push(make_pair(nextx, nexty));
            }
        }
    }
    int ans = -1;
    if(shotestpath != -1) ans = white - shotestpath;
    cout << ans << endl;
}
