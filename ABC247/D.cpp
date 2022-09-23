#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 710
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	deque<pair<ll, ll>> deq;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int x,c;
			cin >> x >> c;
			deq.push_back(make_pair(x, c));
		}else if(op == 2){
			int c;
			cin >> c;
			ll ans = 0;
			while(c > 0){
				auto t = deq[0];
				debug(t);
				deq.pop_front();
				if(t.second <= c){
					ans += t.first * t.second;
					c -= t.second;
				}else{
					ans += t.first * c;
					deq.push_front(make_pair(t.first, t.second - c));
					c = 0;
				}
				debug(deq);
			}
			cout << ans << endl;
		}
	}
}
