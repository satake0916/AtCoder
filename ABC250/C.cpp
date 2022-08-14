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
	int n,q;
	cin >> n >> q;
	int a[n], mp[n+1];
	for(int i = 1; i <= n; i++){
		a[i-1] = i;
		mp[i] = i-1;
	}

	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		int ind = mp[x];
		int nind = ind+1;
		if(nind >= n) nind -= 2;
		int v = a[ind];
		int nv = a[nind];

		a[nind] = v;
		a[ind] = nv;

		mp[v] = nind;
		mp[nv] = ind;
	}

	for(int i = 0; i < n; i++){
		cout << a[i];
		if(i != n-1) cout << " ";
	}
	cout << endl;
}
