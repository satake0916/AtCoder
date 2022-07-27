#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define pair make_pair
#define all(x) (x).begin(), (x).end()

vector<int> pre(10000001, 1);

int sol(int n){
	int cnt = 0;
	while(n > 1){
		int p = pre[n];
		cnt++;
		while(pre[n] == p){
			n /= p;
		}
	}
	return cnt;
}

int main(){

	int n,k;
	cin >> n >> k;
	int ans = 0;
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i <= n; i++){
		if(is_prime[i]){
			pre[i] = i;
			for(int j = i*2; j <= n; j+=i){
				is_prime[j] = false;
				if(pre[j] == 1) pre[j] = i;
			}
		}
		int t = sol(i);
		if(t >= k){
			ans++;
		}
	}

	cout << ans << endl;
}
