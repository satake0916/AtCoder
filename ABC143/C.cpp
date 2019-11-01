#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    char last = s[0];
    for(int i = 1; i < n; i++){
        if(last != s[i]){
            ans++;
            last = s[i];
        }
    }
    ans++;
    cout << ans << endl;
}
