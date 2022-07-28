#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b){
	if(a < b) return gcd(b, a);
	return (b ? gcd(b, a%b) : a);
}

int main(){
	ll a,b;
	cin >> a >> b;
	ll g = gcd(a, b);
	a /= g;
	const ll big = 1000000000000000000LL;
	if(big / a < b){
		cout << "Large" << endl;
	}else{
		cout << a * b << endl;
	}
}
