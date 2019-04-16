#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

string s;
int x,y,n;
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int f = 0, t = 0;
vector<int> restf;

bool dfs(int step, int dir, pair<int, int> point){
    //cout << "step: " << step << "  dir: " << dir << "  point: " << point.first << " " << point.second << endl;
    if(step == n){
        if(x == point.first && y == point.second) return true;
        else return false;
    }
    if(abs(x - point.first) + abs(y - point.second) > restf[step]) return false;
    
    if(s[step] == 'F') return dfs(step+1, dir, make_pair(point.first+dx[dir], point.second+dy[dir]));
    
    int nextdir[] = {0,0};
    if(dir == 0 || dir == 2) nextdir[0] = 1, nextdir[1] = 3;
    else if(dir == 1 || dir == 3) nextdir[0] = 0, nextdir[1] = 2;

    return dfs(step+1, nextdir[0], point) || dfs(step+1, nextdir[1], point);
}

int main(){
    cin >> s >> x >> y;
    n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == 'F') f++;
        else t++;
    }
    restf.resize(n);
    restf[0] = f;
    for(int i = 0; i < n-1; i++){
        restf[i+1] = restf[i];
        if(s[i] == 'F') restf[i+1]--;
    }
    cout << (dfs(0,0,make_pair(0,0)) ? "Yes" : "No") << endl;
}
