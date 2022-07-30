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
	int q;
	cin >> q;
	deque<int> deq;
	rep(i, 0, q){
		int t,x;
		cin >> t >> x;
		if(t == 1){
			deq.push_front(x);
		}else if(t == 2){
			deq.push_back(x);
		}else if(t == 3){
			cout << deq[x-1] << endl;
		}
	}
}
