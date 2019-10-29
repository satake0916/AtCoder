#include "bits/stdc++.h"
using namespace std;

template<typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    map<int, int> mp;
    for (int i = 2; (long long)i * i <= g; i++) {
        while (g % i == 0) {
            mp[i]++;
            g /= i;
        }
    }
    if (g > 1) mp[g]++;
    cout << mp.size() + 1 << endl;
}
