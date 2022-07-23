#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	int cnt = 0;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n){
		int b;
		cin >> b;
		cnt += abs(b - a[i]);
	}
	bool f = cnt <= k;
	f &= ((k-cnt)%2 == 0);

	cout << (f ? "Yes" : "No") << endl;

}
