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

const int MAX = 300;
int flag[MAX+1][MAX+1][MAX+1];
double dp[MAX+1][MAX+1][MAX+1];
int N;

double f(int c1, int c2, int c3){
	if(c1 == 0 && c2 == 0 && c3 == 0) return 0;
	if(flag[c1][c2][c3]) return dp[c1][c2][c3];
	flag[c1][c2][c3] = 1;
	double zero = (double)(N-c1-c2-c3) / N;
	double ret = 1/(1 - zero);
	if(c1 > 0) ret += f(c1-1, c2, c3) * c1 / N / (1-zero);
	if(c2 > 0) ret += f(c1+1, c2-1, c3) * c2 / N / (1-zero);
	if(c3 > 0) ret += f(c1, c2+1, c3-1) * c3 / N / (1 - zero);
	return dp[c1][c2][c3] = ret;
}

int main(){
	cin >> N;
	vector<int> c(4, 0);
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		c[a]++;
	}
	double ans = f(c[1], c[2], c[3]);
	cout << fixed << setprecision(10) << ans << endl;
}
