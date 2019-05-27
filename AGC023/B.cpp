#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<char> > area(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> area[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        bool f = true;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(area[(i+j)%n][k] != area[(i+k)%n][j]) f = false;
            }
        }
        if(f) ans++;
    }
    cout << ans * n << endl;
}
