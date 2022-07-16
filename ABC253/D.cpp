#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
	return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
	return a * b / gcd(a,b);
}

int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	if(a<b){
		int t = a;
		a = b;
		b = t;
	}
	ll sum = n * (n+1) /2;
	ll anum = n/a;
	ll bnum = n/b;
	ll abnum = n/lcm(a,b);
	cout << gcd(a,b) << endl;
	ll ans = 0;
	if(a==b){
		ans = sum - (a*(anum*(anum+1)/2));
	}else{
		ans = sum - (a * (anum * (anum+1) / 2)) - (b*(bnum*(bnum+1)/2)) + (lcm(a,b)*(abnum*(abnum+1)/2));
	}
	cout << ans << endl;
}
