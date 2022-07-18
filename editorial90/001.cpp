#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n,l,k;
int a[100000];

bool isOK(int mid){
	int pre = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] - pre >= mid){
			cnt++;
			pre = a[i];
		}
	}
	if(l - pre < mid) cnt--;
	return cnt >= k;
}

int main(){
	cin >> n >> l;
	cin >> k;
	rep(i, 0, n) cin >> a[i];

	int rv = 0;
	int lv = l;
	while(lv - rv > 1){
		int mid = (rv + lv) / 2;
		bool ok = isOK(mid);
		if(ok) rv = mid;
		else lv = mid;
	}

	cout << rv << endl;
}
