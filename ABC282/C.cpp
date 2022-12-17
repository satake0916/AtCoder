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
	int n;
	string s;
	cin >> n >> s;
	string ans = "";
	bool kuku = false;
	for(int i = 0; i < n; i++){
		if(s[i] == '"'){
			kuku ^= true;
		}

		if(s[i] == ','){
			if(!kuku) ans += '.';
			else ans += ',';
		}else{
			ans += s[i];
		}
	}

	cout << ans << endl;
}
