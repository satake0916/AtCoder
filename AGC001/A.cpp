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
	int n;
	cin >> n;
	vector<int> l(2*n);
	for(auto &x: l) cin >> x;
	sort(l.begin(), l.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += l[2 * i];
	}
	cout << ans << endl;
}
