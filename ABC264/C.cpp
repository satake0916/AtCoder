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
	int h1, w1;
	cin >> h1 >> w1;
	bool ans = false;
	int a[h1][w1];
	for(int i = 0; i < h1; i++){
		for(int j = 0; j < w1; j++){
			cin >> a[i][j];
		}
	}

	int h2,w2;
	cin >> h2 >> w2;
	int b[h2][w2];
	for(int i = 0; i < h2; i++){
		for(int j = 0; j < w2; j++){
			cin >> b[i][j];
		}
	}

	for(int h = 0; h < (1 << h1); h++){
		for(int w = 0; w < (1 << w1); w++){
			bool f = true;
			if(__builtin_popcount(h) != h2 || __builtin_popcount(w) != w2) continue;
			
			int i2 = 0;
			for(int i1 = 0; i1 < h1; i1++){
				int j2 = 0;
				if(!((1 << (h1 - 1 - i1)) & h)) continue;
				for(int j1 = 0; j1 < w1; j1++){
					if(((1 << (w1 - 1 - j1)) & w)){
						if(a[i1][j1] != b[i2][j2]) f = false;
						j2++;
					}
				}
				i2++;
			}
			if(f) ans = true;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;


}

