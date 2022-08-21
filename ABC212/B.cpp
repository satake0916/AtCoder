#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int x;
	cin >> x;
	int y[4];
	y[0] = x / 1000;
	y[1] = (x / 100) % 10;
	y[2] = (x / 10) % 10;
	y[3] = x % 10;

	bool f = true, g = true;
	for(int i = 0; i < 3; i++){
		f = f && (y[i] == y[i+1]);
		g = g && ((y[i]+1) % 10 == y[i+1]);
	}

	if(f || g) cout << "Weak" << endl;
	else cout << "Strong" << endl;
}
