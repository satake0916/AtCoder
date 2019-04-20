#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

const int MOD = 998244353;
const int N = 900100;
vector<int> colors(N,0);
vector<vector<pair<int, vector<bool> > > >d(N);
vector<bool> exist(N);

bool ok(bool a, bool b, bool c){
    if(a && (!b && !c)) return true;
    if(!a && (b && !c)) return true;
    if(!a && (!b && c)) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    d[0].push_back(make_pair(0, vector<bool>(n,false)));
    exist[0] = true;
    
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < N; j++){
            if(exist[j] && j + a[i] < N){
                exist[j+a[i]] = true;
                for(auto t : d[j]){
                    int trues = t.first;
                    vector<bool> tt = t.second;
                    tt[i] = true;
                    d[j+a[i]].push_back(make_pair(trues+1, tt));
                }
            }
        }
    }

    for(int i = 0; i < 6; i++){
        for(auto t: d[i]){
            vector<bool> te = t.second;
            for(int j = 0; j < te.size(); j++) cout << te[j] << " ";
            cout << endl;
        }
        cout << endl << endl;
    }

    long long ans = 0;
    for(int i = sum; i >= 0; i++){
        int rest = sum - i;
        if(rest > i && exist[i]){
            for(auto t: d[i]){
                int falses = n - t.first;
                vector<bool> tv = t.second;
                for(int j = rest - 1; j > 0; j--){
                    if(j > i || (rest-j) > i) break;
                    if(exist[j] && exist[rest- j]){
                        for(auto s: d[j]){
                            for(auto u: d[rest - j]){
                                for(int k = 0; k < n; k++){
                                    if(!ok(tv[k], s.second[k], u.second[k])) break;
                                }
                                (ans += 1) %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
