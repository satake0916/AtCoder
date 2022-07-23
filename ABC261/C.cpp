#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n;
	cin >> n;
	map<string, int> m;
	rep(i, 0, n){
		string s;
		cin >> s;
		if(m[s] == 0){
			cout << s << endl;
			m[s]++;
		}else{
			cout << s << "(" << m[s] << ")" << endl;
			m[s]++;
		}
	}
}
