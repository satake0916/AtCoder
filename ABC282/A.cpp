#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	string ans = "";
	char t = 'A';
	for(int i = 0; i < k; i++){
		ans += t;
		t++;
	}
	cout << ans << endl;
}
