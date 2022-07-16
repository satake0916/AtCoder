#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int q;
	cin >> q;
	map<int, int> mp;
	int r = 0, l = 0;
	for(int i = 0; i < q; i++){
		int a;
		cin >> a;
		if(a == 1){
			int x;
			cin >> x;
			mp[x]++;
			r = min(r, x);
			l = max(l, x);
		}else if(a == 2){
			int x,c;
			cin >> x >> c;
			if(c >= mp[x]) mp.erase(x);
			else mp[x] = mp[x] - c;
		}else{
			cout << (--mp.end())->first - mp.begin()->first << endl;
		}
	}
}
