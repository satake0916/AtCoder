#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n,k;
	cin >> n >> k;
	int a[n], b[k];
	int ma = -1;
	bool f = false;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	for(int i = 0; i < k; i++){
		cin >> b[i];
		if(a[b[i]-1] == ma) f = true;
	}

	cout << (f ? "Yes" : "No") << endl;
}
