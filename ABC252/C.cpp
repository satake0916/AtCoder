
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	int ans = n*10;
	for(int i = 0; i < 10; i++){
		char target = '0' + i;
		vector<bool> f(n);
		for(int j = 0; j <= n*10 ; j++){
			int time = j%10;
			for(int k = 0; k < n; k++){
				if(s[k][time] == target && !f[k]){
					f[k] = true;
					break;
				}
			}
			bool s = true;
			for(int k = 0; k < n; k++){
				s &= f[k];
			}
			if(s){
				ans = min(ans, j);
				break;
			}
		}
	}
	cout << ans << endl;
}
