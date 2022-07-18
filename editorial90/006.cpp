#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main(){
	ll n,k;
	cin >> n >> k;
	string s;
	cin >> s;

	list<char> l;

	rep(i, 0, k){
		l.pb(s[i]);
	}

	auto it = l.begin();
	while(next(it) != l.end() && (*(it) <= *next(it))){
		it++;
	}

	rep(i, k, n){
		l.pb(s[i]);
		if(*it > *next(it)){
			auto temp = prev(it);
			l.erase(it);
			it = l.begin();
			//it = temp;
			//cout << *it << endl;
		}else{
			l.pop_back();
		}
		while(next(it) != l.end() && (*(it) <= *next(it))){
			it++;
		}
	}

	for(auto itr = l.begin(); itr != l.end(); itr++){
		cout << *itr;
	}
	cout << endl;
}
