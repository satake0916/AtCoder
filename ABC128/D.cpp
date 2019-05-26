#include "bits/stdc++.h"
using namespace std;
using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

int main()
{
    ll n,k;
    cin >> n >> k;
    deque<ll> v;
    for(ll i = 0; i < n; i++){
        ll t;
        cin >> t;
        v.push_back(t);
    }
    
    ll ans = -LINF;
    //i個使う(k-i個捨てる)
    for(ll i = k; i >= k/2; i--){
        //j個を前から取る
        for(ll j = 0; j <= i; j++){
            deque<ll> td = v;
            vector<ll> temp;
            for(int front = 0; front < j; front++){
                if(td.empty()) break;
                temp.push_back(td.front());
                td.pop_front();
            }
            for(int back = 0; back < i - j; back++){
                if(td.empty()) break;
                temp.push_back(td.back());
                td.pop_back();
            }
            sort(temp.begin(), temp.end());
            ll tempans = 0;
            for(int num = 0; num < i; num++){
                if(num >= temp.size()) break;
                if(num < k - i && temp[num] < 0) continue;
                else{
                    tempans += temp[num];
                }
            }
            ans = max(ans, tempans);
        }
    }
    cout << ans << endl;
}
