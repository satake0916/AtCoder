
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const ll MOD = 1e9+7;
const int MAX_N = 33;

struct Matrix{
	int sz;
	ll x[MAX_N][MAX_N];
};

Matrix multiply(Matrix A, Matrix B) {
	// A × B を求める
	Matrix C;
	C.sz = A.sz;
	for (int i = 0; i < C.sz; i++) {
		for (int j = 0; j < C.sz; j++) C.x[i][j] = 0;
	}
	for (int i = 0; i < A.sz; i++) {
		for (int j = 0; j < A.sz; j++) {
			for (int k = 0; k < A.sz; k++) {
				C.x[i][k] += A.x[i][j] * B.x[j][k];
				C.x[i][k] %= MOD;
			}
		}
	}
	return C;
}

Matrix powers(Matrix A, long long T) {
	// A の T 乗を求める
	Matrix E[64], F;
	E[0] = A;
	for (int i = 1; i < 62; i++) {
		E[i] = multiply(E[i - 1], E[i - 1]);
	}

	F.sz = E[0].sz;
	for (int i = 0; i < F.sz; i++) {
		for (int j = 0; j < F.sz; j++) {
			if (i == j) F.x[i][j] = 1;
			if (i != j) F.x[i][j] = 0;
		}
	}

	for (int i = 62; i >= 0; i--) {
		if ((T & (1LL << i)) != 0LL) {
			F = multiply(F, E[i]);
		}
	}
	return F;
}

int main(){
	ll n,b,k;
	cin >> n >> b >> k;
	ll c[k];
	rep(i, 0, k) cin >> c[i];

	Matrix A;
	A.sz = b;
	rep(i, 0, b){
		rep(j, 0, b){
			A.x[i][j] = 0;
		}
	}
	rep(i, 0, b){
		for(ll x: c){
			int next = (i * 10 + x) % b;
			A.x[i][next]++;
		}
	}

	Matrix Z = powers(A, n);

	cout << Z.x[0][0] << endl;
}
