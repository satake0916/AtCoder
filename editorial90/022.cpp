#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

template<typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll g = gcd(a, gcd(b, c));
	cout << (a/g - 1) + (b/g - 1) + (c/g - 1) << endl;
}
