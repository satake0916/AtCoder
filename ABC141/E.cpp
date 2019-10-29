#include "bits/stdc++.h"
using namespace std;
 
int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int len = 0;
        for(int j = 0; j < n; j++){
            if(s[i+j] == s[j] && i+j-len != j){
                len++;
            }else{
                ans = max(ans, len);
                len = 0;
            }
        }
    }
    cout << ans << endl;
}
