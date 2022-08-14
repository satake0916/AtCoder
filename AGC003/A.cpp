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
	cin >> s;
	int n = s.size();
	map<char, int> mp;
	for(int i = 0; i < n; i++) mp[s[i]]++;
	bool f = (mp['N'] > 0 && mp['S']) || (mp['N'] == 0 && mp['S'] == 0);
	bool g = (mp['W'] > 0 && mp['E']) || (mp['W'] == 0 && mp['E'] == 0);
	cout << (f&&g ? "Yes" : "No") << endl;
}
