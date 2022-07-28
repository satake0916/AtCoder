#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	set<string> st;
	int mx = -1;
	int ans = -1;
	rep(i, 0, n){
		string s;
		int t;
		cin >> s >> t;
		if(st.count(s)) continue;
		st.insert(s);
		if(t > mx){
			mx = t;
			ans = i+1;
		}
	}
	cout << ans << endl;
}
