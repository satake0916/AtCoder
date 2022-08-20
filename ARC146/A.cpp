#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int getDigit(int x){
	int d = 0;
	while(x > 0){
		x /= 10;
		d++;
	}
	return d;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> nums(10);
	vector<int> digit(n);
	for(int i = 0; i < n; i++){
		digit[i] = getDigit(a[i]);
		nums[digit[i]].push_back(a[i]);
	}

	sort(digit.begin(), digit.end(), greater<int>{});
	for(int i = 0; i < nums.size(); i++){
		sort(nums[i].begin(), nums[i].end(), greater<int>{});
	}

	vector<int> ind(10, 0);
	int use[3];
	for(int i = 0; i < 3; i++){
		int d = digit[i];
		use[i] = nums[d][ind[d]];
		ind[d]++;
	}

	ll ans = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			int k = 3 - i - j;
			ll t = use[i];
			for(int foo = 0; foo < getDigit(use[j]); foo++) t *= 10;
			t += use[j];
			for(int bar = 0; bar < getDigit(use[k]); bar++) t *= 10;
			t += use[k];
			ans = max(ans, t);
		}
	}
	cout << ans << endl;
}

