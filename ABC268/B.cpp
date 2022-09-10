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
	string s,t;
	cin >> s >> t;
	if(s.size() > t.size()){
		cout << "No" << endl;
		return 0;
	}else{
		for(int i = 0; i < s.size(); i++){
			if(s[i] != t[i]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
