#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n,m,t;
	cin >> n >> m >> t;
	vector<ll> a(n-1);
	for(int i = 0; i < n-1; i++) cin >> a[i];
	vector<ll> x(m), y(m);
	for(int i = 0; i < m; i++){
		cin >> x[i] >> y[i];
		x[i]--;
	}

	int room = 0;
	for(int i = 0; i < n-1; i++){
		if(t <= a[i]){
			cout << "No" << endl;
			return 0;
		}
		t -= a[i];
		assert(t > 0);
		if(room < m && x[room] == i+1){
			t += y[room];
			room++;
		}
	}
	cout << "Yes" << endl;
}

