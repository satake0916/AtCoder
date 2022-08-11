#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int main(){
	int k,n;
	cin >> n >> k;
	int a[n];
	for(auto &x: a) cin >> x;
	vector<int> dp(k+1, 0);
	for(int i = 0; i <= k; i++){
		for(int j = 0; j < n; j++){
			if(i - a[j] >= 0){
				if(dp[i - a[j]] == 0) dp[i] = 1;
			}
		}
	}

	cout << (dp[k] ? "First" : "Second") << endl;
}
