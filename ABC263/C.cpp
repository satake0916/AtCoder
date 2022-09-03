#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(arg) print(#arg, arg)

template <class Tp> void print(string_view name, Tp arg) {
  cerr << "(debug) " <<  name << " = " << arg << endl;
}

template <class Tp> void print(string_view name, vector<Tp> arg) {
  cerr << "(debug) " << name << " = [ ";
  copy(cbegin(arg), cend(arg), ostream_iterator<Tp>(cerr, " "));
  cerr << "]" << endl;;
}

#else
#define debug(arg) true
#endif

void fun(int n, int m, vector<int> &v){
	int l = v[v.size()-1];
	if(v.size() == n){
		for(int i = 1; i < n; i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}else{
			for(int nxt = l+1; nxt <= m; nxt++){
				v.push_back(nxt);
				fun(n, m, v);
				v.pop_back();
			}
	}
}
		

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<int> v(1, 0);
	fun(n+1, m, v); 
}
