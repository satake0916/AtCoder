#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

ll string8_to_ll(string s){
	ll ret = 0;
	rep(i, 0, s.size()){
		ret = ret * 8 + int(s[i] - '0');
	}
	return ret;
}

string ll_to_string9(ll n){
	if(n == 0) return "0";
	string ret = "";
	while(n > 0){
		ret = char(n%9 + '0') + ret;
		n /= 9;
	}
	return ret;
}

int main(){
	string n;
	int k;
	cin >> n >> k;
	rep(i, 0, k){
		n = ll_to_string9(string8_to_ll(n));
		rep(j, 0, n.size()){
			if(n[j] == '8') n[j] = '5';
		}
	}

	cout << n << endl;
}
