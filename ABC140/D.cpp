#include "bits/stdc++.h"
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    int bound = 0;
    char last = s[0];
    for(int i = 1; i < n; i++){
        if(last == s[i]) ans++;
        else bound++;
        last = s[i];
    }

    cout << ans + min(bound, 2*k) << endl;
}
