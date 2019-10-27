#include "bits/stdc++.h"
using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        string x,y;
        cin >> x >> y;
        int nx = x.length();int ny = y.length();
        int dp[nx][ny];
        dp[0][0] = x[0] == y[0];
        for(int i = 1; i < nx; i++) dp[i][0] = x[i] == y[0] || dp[i-1][0];
        for(int j = 1; j < ny; j++) dp[0][j] = y[j] == x[0] || dp[0][j-1];
        for(int i = 1; i < nx; i++){
            for(int j = 1; j < ny; j++){
                if(x[i] == y[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout << dp[nx-1][ny-1] << endl;
    }
}
