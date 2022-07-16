#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<int> c(10);
	for(int i = 1; i <= 9; i++) cin >> c[i];

	int mn = *min_element(c.begin()+1, c.end());
	int len = n / mn;

	string ans = "";

	for(int i = 0; i < len; i++){
		for(int j = 9; j > 0; j--){
			if((ll)mn * (len - i - 1) + c[j] <= n){
				n -= c[j];
				ans.push_back((char)('0'+j));
				break;
			}
		}
	}

	cout << ans << endl;
}
