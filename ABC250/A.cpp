#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int h,w,r,c;
	cin >> h >> w >> r >> c;
	int ans = 4;
	if(r == 1) ans--;
	if(r == h) ans--;
	if(c == 1) ans--;
	if(c == w) ans--;
	cout << ans << endl;
}
