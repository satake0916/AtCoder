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
    int ans = INF;
    for(int i = 1; i < n; i++){
        int a = i, b = n-i;
        int temp = 0;
        while(a > 0){
            temp += a % 10;
            a /= 10;
        }
        while(b > 0){
            temp += b % 10;
            b /= 10;
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
}
