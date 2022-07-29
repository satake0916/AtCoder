#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,q;
	cin >> n >> q;
	vector<int> a(n), ind(n);
	rep(i, 0, n){
		cin >> a[i];
		ind[i] = i;
	}

	int s = 0;
	rep(i, 0, q){
		int t,x,y;
		cin >> t >> x >> y;
		x--, y--;
		if(t == 1){
			int t = ind[(s+x)%n];
			ind[(s+x)%n] = ind[(s+y)%n];
			ind[(s+y)%n] = t;
		}else if(t == 2){
			s--;
			s += n;
			s %= n;
		}else if(t == 3){
			cout << a[ind[(s+x)%n]] << endl;
		}
	}
}
