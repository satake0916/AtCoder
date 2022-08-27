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

int main(){
	int n;
	cin >> n;
	vector<double> kitai(n+1);
	kitai[0] = 0;

	for(int i = 1; i <= n; i++){
		double sum = 0;
		for(int j = 1; j <= 6; j++){
			if(j < kitai[i-1]) sum += kitai[i-1];
			else sum += j;
		}
		kitai[i] = sum / 6.0;
	}

	cout << fixed << setprecision(10) << kitai[n] << endl;
}
