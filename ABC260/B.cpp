#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n,x,y,z;
	cin >> n >> x >> y >> z;
	vector<pair<int, int> > a(n), b(n), c(n);
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		a[i] = make_pair(t, i);
	}
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		b[i] = make_pair(t, i);
		c[i] = make_pair(a[i].first+b[i].first, i);
	}
	auto func = [](auto const& lhs, auto const& rhs){
		if(lhs.first == rhs.first) return lhs.second < rhs.second;
		return lhs.first > rhs.first;
	};
	sort(a.begin(), a.end(), func);
	sort(b.begin(), b.end(), func);
	sort(c.begin(), c.end(), func);


	vector<bool> ok(n);

	for(int i = 0; i < x; i++){
		ok[a[i].second] = true;
	}

	int cnt = 0;
	int ind = 0;
	while(cnt < y){
		if(!ok[b[ind].second]){
			ok[b[ind].second] = true;
			cnt++;
			ind++;
		}else{
			ind++;
		}
	}
	
	cnt = 0;
	ind = 0;
	while(cnt < z){
		if(!ok[c[ind].second]){
			ok[c[ind].second] = true;
			cnt++;
			ind++;
		}else{
			ind++;
		}
	}

	for(int i = 0; i < n; i++){
		if(ok[i]) cout << i+1 << endl;
	}

}
