#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	bool f = false;
	ll t = 1;
	rep(i, 0, b){
		if(a / c < t){
			f = true;
			break;
		}else{
			t *= c;
		}
	}
	cout << (f ? "Yes" : "No") << endl;
}
