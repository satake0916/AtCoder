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
	int now = 1;
	int ans[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j += 2){
			ans[i][j] = now;
			now++;
		}
		for(int j = 1; j < n; j += 2){
			ans[i][j] = now;
			now++;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j];
			if(j != n-1) cout << " ";
		}
		cout << endl;
	}
}
