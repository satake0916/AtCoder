#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	vector<vector<int> > inv(m+1);
	for(int i = 0; i < n; i++){
		inv[a[i]].push_back(i);
		inv[b[i]].push_back(i);
	}

	vector<int> cnt(n), ans(m+1);
	int remain = n;
	for(int i = 1, j = 1; i <= m; ){
		while(j <= m && remain != 0){
			for(int x: inv[j]){
				if(cnt[x] == 0) remain--;
				cnt[x]++;
			}
			j++;
		}
		if(remain != 0) break;
		ans[j-i]++;
		if(m-i+1+1 <= m) ans[m-i+1+1]--;

		for(int x: inv[i]){
			cnt[x]--;
			if(cnt[x] == 0) remain++;
		}
		i++;
	}

	for(int i = 1; i <= m; i++){
		ans[i] += ans[i-1];
		cout << ans[i] << " ";
	}
	cout << endl;
}

