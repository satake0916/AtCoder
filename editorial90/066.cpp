#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int main(){
	int n;
	cin >> n;
	int l[n], r[n];
	int len[n];
	ll prod = 1;
	rep(i, 0, n){
		cin >> l[i] >> r[i];
		len[i] = r[i] - l[i] + 1;
		prod *= len[i];
	}

	long double kitai = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int num = 0;
			for(int i_num = l[i]; i_num <= r[i]; i_num++){
				for(int j_num = l[j]; j_num <= r[j]; j_num++){
					if(i_num > j_num){
						num++;
					}
				}
			}
			kitai += (long double)num / len[i] / len[j];
		}
	}

	cout << fixed << setprecision(10) << kitai << endl;
}
