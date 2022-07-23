#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, 0, n) cin >> a[i];

	bool f = true;
	rep(i, 0, n){
		rep(j, i+1, n){
			if(a[i][j] == 'W' && a[j][i] != 'L') f = false;
			if(a[i][j] == 'L' && a[j][i] != 'W') f = false;
			if(a[i][j] == 'D' && a[j][i] != 'D') f = false;
		}
	}

	cout << (f ? "correct" : "incorrect") << endl;
}
