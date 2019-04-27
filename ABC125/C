#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

template<typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> front(n), back(n);
    int temp = a[0];
    for(int i = 0; i < n; i++){
        temp = gcd(temp, a[i]);
        front[i] = temp;
    }
    temp = a[n-1];
    for(int i = n-1; i >= 0; i--){
        temp = gcd(temp, a[i]);
        back[i] = temp;
    }
    int ans = max(front[n-2], back[1]);
    for(int i = 1; i < n-1; i++){
        int t = gcd(front[i-1], back[i+1]);
        ans = max(ans, t);
    }
    cout << ans << endl;
}
