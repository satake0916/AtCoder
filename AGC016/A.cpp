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
    int ret = INF;
    int n = s.size();
    vector<int> sint(n);
    for(int i = 0; i < n; i++){
        sint[i] = s[i] - 'a';
    }
    for(int ch = 0; ch < 26; ch++){
        int tans = n;
        vector<int> tsint = sint;
        for(int ans = 0; ans < n; ans++){
            bool f = true;
            for(int j = 0; j < tsint.size(); j++){
                if(tsint[j] != ch) f = false;
            }
            if(f){
                tans = ans;
                break;
            }

            vector<int> ttsint(tsint.size()-1, '-');
            for(int j = 0; j < ttsint.size(); j++){
                if(tsint[j] == ch || tsint[j+1] == ch) ttsint[j] = ch;
            }
            tsint = ttsint;
        }
        ret = min(ret, tans);
    }
    cout << ret << endl;
}
