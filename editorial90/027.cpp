#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	set<string> st;
	rep(i, 0, n){
		string s;
		cin >> s;
		if(st.count(s)) continue;
		st.insert(s);
		cout << i+1 << endl;
	}
}
