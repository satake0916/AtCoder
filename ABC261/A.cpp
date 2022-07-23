#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	int len = min(r1, r2) - max(l1, l2);
	cout << max(len, 0) << endl;
}
