#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n;

void solve(string s, int l, int r){
	if(l + r == n){
		if(l == r) cout << s << endl;
		return;
	}

	solve(s+'(', l+1, r);
	if(l > r) solve(s+')', l, r+1);
}


int main(){
	cin >> n;
	solve("", 0, 0);
}
