#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int q;
	cin >> q;
	priority_queue<ll, vector<ll>, greater<ll>> que;
	ll up = 0;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			ll x;
			cin >> x;
			que.push(x - up);
		}else if(op == 2){
			ll x;
			cin >> x;
			up += x;
		}else if(op == 3){
			cout << que.top() + up << endl;
			que.pop();
		}
	}
}
