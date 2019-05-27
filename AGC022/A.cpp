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
    int n = s.size();
    vector<bool> used(n, false);
    for(int i = 0; i < n; i++){
        used[s[i] - 'a'] = true;
    }
    if(n < 26){
        for(int i = 0; i < 26; i++){
            if(!used[i]){
                cout << s << (char)('a'+i) << endl;
                break;
            }
        }
    }else{
        int id = -1;
		for(int i = n - 2; i >= 0; i--){
            if(s[i] < s[i+1]){
                id = i;
                break;
            }
        }

		if(id == -1){
            cout << -1 << endl;
        }else{
            string t = s.substr(0,id);
            int idx2 = id + 1;
            for(int i = idx2; i < n; i++){
                if(s[i] < s[idx2] && s[i] > s[id]) idx2 = i;
            }
            t += s[idx2];
            cout << t << endl;
        }
    }
}
