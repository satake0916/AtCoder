#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int h,w;
	cin >> h >> w;
	if(h == 1 || w == 1) cout << h*w << endl;
	else cout << ((h+1)/2) * ((w+1)/2) << endl;
}
