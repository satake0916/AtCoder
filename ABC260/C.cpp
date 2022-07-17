#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll n,x,y;
	cin >> n >> x >> y;
	ll a = 1, b = 0;
	for(int i = 1; i < n; i++){
		ll na = a + x * a + b;
		ll nb = (x * a + b) * y;
		a = na;
		b = nb;
	}

	cout << b << endl;
}
