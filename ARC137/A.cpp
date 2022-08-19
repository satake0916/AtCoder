#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll l,r;
	cin >> l >> r;
	for(ll x = (r - l); x > 0; x--){
		for(ll l_ = l; l_ + x <= r; l_++){
			if(gcd(l_, l_ + x) == 1){
				cout << x << endl;
				return 0;
			}
		}
	}
}
