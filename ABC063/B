#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<bool> a(s.size(), false);
    for(int i = 0; i < s.size(); i++){
        if(a[s[i] - 'a']){
            cout << "no" << endl;
            return 0;
        }else{
            a[s[i] - 'a'] = true;
        }
    }
    cout << "yes" << endl;
}
