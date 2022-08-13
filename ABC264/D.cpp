#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>

using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int main(){
	string s;
	string t = "atcoder";
	cin >> s;
	int a[s.size()];
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < t.size(); j++){
			if(s[i] == t[j]){
				a[i] = j;
				break;
			}
		}
	}

	int cnt = 0;
	bool f = true;
	while(f){
		f = false;
		for(int i = 0; i < s.size() - 1; i++){
			if(a[i] > a[i+1]){
				cnt++;
				int t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
				f = true;
			}
		}
	}

	cout << cnt << endl;
}

