#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	int n,k;
	string s;
	cin >> n >> k;
	cin >> s;

	int nex[n+1][26];
	rep(i, 0, 26) nex[n][i] = n;
	for(int i = n-1; i >= 0; i--){
		rep(j, 0, 26){
			if(s[i] == (char)('a' + j)) nex[i][j] = i;
			else nex[i][j] = nex[i+1][j];
		}
	}

	string ans = "";
	int now = 0;
	rep(i, 0, k){
		rep(j, 0, 26){
			int next = nex[now][j];
			int rest = k-i-1;
			int possible = n - next - 1;
			if(possible >= rest){
				ans += (char)('a'+j);
				now = next+1;
				break;
			}
		}
	}

	cout << ans << endl;
}
