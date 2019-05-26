#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    map<string, vector<pair<int, int> > > mp;
    for(int i = 0; i < n; i++){
        string s;
        int p;
        cin >> s >> p;
        mp[s].push_back(make_pair(p, i+1));
    }
    for(auto i: mp){
        sort(i.second.begin(), i.second.end());
        reverse(i.second.begin(), i.second.end());
        for(auto p : i.second){
            cout << p.second << endl;
        }
    }
}
