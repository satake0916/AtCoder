#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <ciso646>
#include <cmath>
#include <complex>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int main() {
	string s = "atcoder";
	int l,r;
	cin >> l >> r;
	for(int i = l; i <= r; i++) cout << s[i-1];
	cout << endl;
}

