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

using Graph = vector<vector<int>>;
// 探索
vector<bool> seen, finished;

// サイクル復元のための情報
int pos = -1; // サイクル中に含まれる頂点 pos
stack<int> hist; // 訪問履歴

void dfs(const Graph &G, int v, int p) {
    seen[v] = true;
    hist.push(v);
    for (auto nv : G[v]) {
        if (nv == p) continue; // 逆流を禁止する

        // 完全終了した頂点はスルー
        if (finished[nv]) continue;

        // サイクルを検出
        if (seen[nv] && !finished[nv]) {
            pos = nv;
            return;
        }

        // 再帰的に探索
        dfs(G, nv, v);

        // サイクル検出したならば真っ直ぐに抜けていく
        if (pos != -1) return;
    }
    hist.pop();
    finished[v] = true;
}

void makeset(set<int> &st, const Graph &G, int s, int p){
	st.insert(s);
	for(int nv: G[s]){
		if(nv == p) continue;
		makeset(st, G, nv, s);
	}
}

int main(){
	// 頂点数 (サイクルを一つ含むグラフなので辺数は N で確定)
    int N; cin >> N;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b; // 頂点番号が 1-indexed で与えられるので 0-indexed にする
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    seen.assign(N, false), finished.assign(N, false);
    pos = -1;
    dfs(G, 0, -1);

    // サイクルを復元
    set<int> cycle;
    while (!hist.empty()) {
        int t = hist.top();
        cycle.insert(t);
        hist.pop();
        if (t == pos) break;
	}

	// サイクルに含まれる頂点ごとに集合を作る
	map<int, set<int>> mp;
	for(auto x: cycle){
		set<int> st;
		st.insert(x);
		for(int nx: G[x]){
			if(cycle.count(nx)) continue;
			makeset(st, G, nx, x);
		}
		mp[x] = st;
	}

	// 集合ごとに頂点のインデックスを浸ける
	vector<int> inc(N);
	for(auto p: mp){
		for(auto item: p.second){
			inc[item] = p.first;
		}
	}

	// クエリにこたえる
	int Q; cin >> Q;
	while(Q--){
		int a,b;
		cin >> a >> b;
		a--, b--;
		cout << (inc[a] == inc[b] ? "Yes" : "No") << endl;
	}
}
