#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int numofa = 0;
    ll ans = 0;
    for(int i = 0; i < n-2; i++){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
            ans += numofa + 1;
            s[i+2] = 'A';
            i++;
        }else if(s[i] == 'A') numofa++;
        else numofa = 0;
    }
    cout << ans << endl;
}
