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
	int n;
	cin >> n;
	int from1[n+1], from2[n+1];
	for(int i = 3; i <= n; i++){
		cout << "? 1 " << i << endl;
		cin >> from1[i];
		if(from1[i] == -1) return 0;

		cout << "? 2 " << i << endl;
		cin >> from2[i];
		if(from2[i] == -1) return 0;
	}

	// 1 and 2 joint?
	/*
	bool f = true;
	for(int i = 3; i < n; i++) f = f && (abs(from1[i] - from2[i]) == abs(from1[i+1] - from2[i+1]));
	bool g = true;
	for(int i = 3; i <= n; i++) g = g && (from1[i] + from2[i] > 2);

	if(f && g){
		cout << "! 1" << endl;
		return 0;
	}
	*/

	int dmn = n;
	for(int i = 3; i <= n; i++){
		dmn = min(dmn, from1[i] + from2[i]);
	}

	int cnt = 0;
	vector<int> check;
	for(int i = 3; i <= n; i++){
		if(dmn == from1[i] + from2[i]) cnt++, check.pb(i);
	}

	bool h = false;
	if(check.size() == 1){
		int ind = check[0];
		h = !(from1[ind] == from2[ind]);
	}else{
				

		int ind1 = check[0], ind2 = check[1];
		int dis;
		cout << "? " << ind1 << " " << ind2 << endl;
		cin >> dis;
		h = !(dis < (cnt+1));
		for(int i = 0; i < check.size(); i++){
			for(int j = i+1; j < check.size(); j++){
				if(from1[ind1] == from1[ind2]) h = true;
			}
		}
	}

	cout << "! " << (h ? 1 : cnt+1) << endl;
}
