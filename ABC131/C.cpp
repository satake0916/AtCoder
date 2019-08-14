#include "bits/stdc++.h"
using namespace std;

template<typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long e = c * d / gcd(c,d);
    long long countc = b/c - (a-1)/c;
    long long countd = b/d - (a-1)/d;
    long long counte = b/e - (a-1)/e;
    cout << b - a + 1 - (countc + countd - counte) << endl;
}
