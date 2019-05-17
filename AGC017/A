#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;

//パスカルの三角形 O(n^2)
long long combination(int n, int r)
{
    if(n < r)
        return 0;
    if(n-r < r)
        r = n-r;
    long long ret = 1;
    for(int i=0; i<r; i++){
        ret *= (n--);
        ret /= i+1;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a%2 == 0) even++;
        else odd++;
    }
    int ans = 0;
    if(p == 0){
        ll fi = 0, se = 0;
        for(int i = 0; i <= even; i++){
            fi += combination(even,i);
        }
        for(int i = 0; i <= odd; i += 2){
            se += combination(odd,i);
        }
        cout << fi * se << endl;
    }else{
        ll fi = 0, se = 0;
        for(int i = 0; i <= even; i++){
            fi += combination(even,i);
        }
        for(int i = 1; i <= odd; i += 2){
            se += combination(odd,i);
        }
        cout << fi * se << endl;        
    }
}
