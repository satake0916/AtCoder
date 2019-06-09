#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char> > area(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> area[i][j];
        }
    }
    vector<vector<int> > ans(h, vector<int>(w,0));
    for(int i = 0; i < h; i++){
        int count = 0;
        for(int j = 0; j < w; j++){
            if(area[i][j] == '.'){
                count++;
                ans[i][j] = count;
            }else{
                ans[i][j] = -1;
                count = 0;
            }
        }
        int now = 0;
        for(int j = w-1; j >= 0; j--){
            if(ans[i][j] == -1){
                now = 0;
            }else{
                now = max(now, ans[i][j]);
                ans[i][j] = now;
            }
        }
    }

    vector<vector<int> > ans2(h, vector<int>(w,0));
    for(int j = 0; j < w; j++){
        int count = 0;
        for(int i = 0; i < h; i++){
            if(area[i][j] == '.'){
                count++;
                ans2[i][j] = count;
            }else{
                ans2[i][j] = -1;
                count = 0;
            }
        }
        int now = 0;
        for(int i = h-1; i >= 0; i--){
            if(ans2[i][j] == -1){
                now = 0;
            }else{
                now = max(now, ans2[i][j]);
                ans2[i][j] = now;
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ret = max(ret, ans[i][j] + ans2[i][j] - 1);
        }
    }
    cout << ret << endl;
}
