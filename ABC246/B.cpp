#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	double a,b;
	cin >> a >> b;

	double len = sqrt(a * a + b * b);

	cout << fixed <<setprecision(10) << a / len << " " << b / len << endl;
}
