#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int w;
	cin >> w;

	vector<int> ans;
	for(int i = 1; i <= 99; i++){
		ans.pb(i);
		ans.pb(i*100);
		ans.pb(i*10000);
	}

	cout << ans.size() << endl;
	for(int x: ans) cout << x << " ";
	cout << endl;
}
