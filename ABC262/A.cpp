#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int y;
	cin >> y;
	while((y-2)%4 != 0) y++;
	cout << y << endl;
}
