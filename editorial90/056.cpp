#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

int main(){
	int n,s;
	cin >> n >> s;
	int a[n], b[n];
	rep(i, 0, n) cin >> a[i] >> b[i];

	vector<pair<int, string> > dp(s+1, make_pair(-1, "C"));
	dp[0].first = 0;
	dp[0].second = "";
	for(int i = 0; i < n; i++){
		for(int j = s; j >= 0; j--){
			if(dp[j].first == i){
				if(a[i] + j <= s){
					dp[a[i]+j].first = dp[j].first + 1;
					dp[a[i]+j].second = dp[j].second + "A";
				}
				if(b[i] + j <= s){
					dp[b[i]+j].first = dp[j].first + 1;
					dp[b[i]+j].second = dp[j].second + "B";
				}
			}
		}
	}

	if(dp[s].first == n) cout << dp[s].second << endl;
	else cout << "Impossible" << endl;
}
