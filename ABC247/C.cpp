#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

string sol(int i, string s){
	string ret = s;
	ret += " ";
	ret += to_string(i);
	ret += " ";
	ret += s;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s = "1";
	for(int i = 2; i <= n; i++){
		s = sol(i, s);
	}

	cout << s << endl;
}
