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

template <typename T>
struct RHQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RHQ(int n_) : n(), dat(n_ * 4, -INF) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return -INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};

int main(){
	int n;
	cin >> n;
	int h[n], a[n];
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	RHQ<ll> rhq(n+1);
	rhq.update(0, 0);
	for(int i = 0; i < n; i++){
		ll temp = rhq.query(0, h[i]);
		rhq.update(h[i], temp+a[i]);
	}
	cout << rhq.query(0, n+1) << endl;
}
