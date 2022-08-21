#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct HashPair {

    //注意 constがいる
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        //first分をハッシュ化する
        auto hash1 = hash<T1>{}(p.first);

        //second分をハッシュ化する
        auto hash2 = hash<T2>{}(p.second);

        //重複しないようにハッシュ処理
        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	ll a[3][2];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			cin >> a[i][j];
		}
	}
	vector<int> x(m), y(m);
	set<pair<ll, ll>> st;
	for(int i = 0; i < m; i++){
		cin >> x[i] >> y[i];
		st.insert(make_pair(x[i], y[i]));
	}
	const int MOD = 998244353;

	vector<ll> dp(n+1);
	dp[0] = 1;
	unordered_map<pair<ll, ll>, ll, HashPair> mp, nmp;
	mp[make_pair(0, 0)]++;

	for(int i = 0; i < n; i++){
		assert(nmp.empty());
		for(auto p: mp){
			for(int j = 0; j < 3; j++){
				auto nxt = make_pair(p.first.first + a[j][0], p.first.second + a[j][1]);
				if(st.find(nxt) == st.end()) (nmp[nxt] += p.second) %= MOD;
			}
		}
		mp = nmp;
		nmp.clear();
	}

	ll ans = 0;
	for(auto p: mp){
		(ans += p.second) %= MOD;
	}

	cout << ans << endl;
}

