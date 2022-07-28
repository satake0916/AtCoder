#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,k;
	cin >> n >> k;
	map<int, int> mp;
	int cnt = 0, ans = 0;
	int a[n];
	rep(i, 0, n) cin >> a[i];

	for(int i = 0, j = 0; i <= n; i++){
		while(cnt <= k && j < n){
			int nxt = a[j];
			if(mp[nxt]){
				j++;
				mp[nxt]++;
			}else{
				if(cnt == k) break;
				cnt++;
				mp[nxt]++;
				j++;
			}
		}

		ans = max(ans, (j-i));

		int pre = a[i];
		mp[pre]--;
		if(mp[pre] == 0) cnt--;
	}

	cout << ans << endl;
}
