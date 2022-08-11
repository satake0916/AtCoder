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

const int MAX = 3001;
int flag[MAX][MAX];
ll dp[MAX][MAX];
ll a[MAX];
int n;

ll f(int l, int r){
	if(flag[l][r]) return dp[l][r];
	flag[l][r] = 1;
	if(l == r) return dp[l][r] = a[l];
	return dp[l][r] = max(a[l] - f(l+1, r), a[r] - f(l, r-1));
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << f(0, n-1) << endl;
}
