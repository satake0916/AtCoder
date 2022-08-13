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

const int MAX = 400;
int n;
ll a[MAX], sum[MAX+1];
ll dp[MAX][MAX];
int flag[MAX][MAX];

ll f(int l, int r){
	if(flag[l][r]) return dp[l][r];
	flag[l][r] = 1;
	if(l == r) return dp[l][r] = a[l];
	ll ret = numeric_limits<ll>::max();
	for(int k = l; k < r; k++){
		ret = min(ret, f(l, k) + f(k+1, r) + sum[r+1] - sum[l]);
	}
	return dp[l][r] = ret;
}


int main(){
	int n;
	cin >> n;
	int a[n];
	for(auto &x: a) cin >> x;
	for(int i = 0; i < n; i++){
		sum[i+1] = sum[i] + a[i];
	}

	cout << f(0, n-1) << endl;
}
