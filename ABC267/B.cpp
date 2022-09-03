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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	vector<int> pins(7, 0);
	if(s[0] == '1') pins[3]++;
	if(s[1] == '1') pins[2]++;
	if(s[2] == '1') pins[4]++;
	if(s[3] == '1') pins[1]++;
	if(s[4] == '1') pins[3]++;
	if(s[5] == '1') pins[5]++;
	if(s[6] == '1') pins[0]++;
	if(s[7] == '1') pins[2]++;
	if(s[8] == '1') pins[4]++;
	if(s[9] == '1') pins[6]++;

	if(s[0] == '1'){
		cout << "No" << endl;
		return 0;
	}

	debug(pins);

	for(int i = 0; i < 7; i++){
		for(int j = i+1; j < 7; j++){
				if(pins[i] > 0 && pins[j] > 0){
					for(int k = i+1; k < j; k++){
						if(pins[k] == 0){
							cout << "Yes" << endl;
							return 0;
						}
					}
				}
		}
	}

	cout << "No" << endl;
}
