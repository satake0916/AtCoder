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

int sankaku(pair<int, int> p, pair<int, int> q){
	return abs(p.first * q.second - p.second * q.first);
}

int main(){
	int ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	pair<int, int> ab = make_pair(bx - ax, by - ay);
	pair<int, int> ac = make_pair(cx - ax, cy - ay);
	pair<int, int> ad = make_pair(dx - ax, dy - ay);

	pair<int, int> ba = make_pair(ax - bx, ay - by);
	pair<int, int> bc = make_pair(cx - bx, cy - by);
	pair<int, int> bd = make_pair(dx - bx, dy - by);

	int s1 = sankaku(ab, ac) + sankaku(ac, ad);
	int s2 = sankaku(ba, bd) + sankaku(bd, bc);

	if(s1 == s2){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

}
