#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
	int x,y,n;
	cin >> x >> y >> n;
	if(3 * x <= y){
		cout << x * n << endl;
	}else{
		cout << y * (n / 3) + (n % 3) * x << endl;
	}
}

