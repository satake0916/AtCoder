#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,l;
	cin >> n >> l;
	const int MOD = 1e9+7;
	vector<int> v(n+1);
	v[0] = 1;
	for(int i = 0; i < n; i++){
		v[i+1] += v[i];
		v[i+1] %= MOD;
		if(i+l <= n){
			v[i+l] = v[i];
			v[i+l] %= MOD;
		}
	}

	cout << v[n] << endl;
}
