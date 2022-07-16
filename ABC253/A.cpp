#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	cout << ((a <= b && b <= c) || (c <= b && b <= a) ? "Yes" : "No") << endl;
}
