#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class dsu {
 public:
  // 根であれば-木のサイズ、根以外であれば親ノードが入っている
  vector<int> p;
  int n;
  vector<map<int, int>> c;
 
  // コンストラクタ
  dsu(int _n, vector<int> c_){
	n = _n;
    p.resize(n, -1);
	c.resize(n);
	for(int i = 0; i < n; i++){
	  c[i][c_[i]]++;
	}
  }
 
  // 頂点xの根を求める
  inline int get(int x) {
    return p[x] < 0 ? x : p[x] = get(p[x]);
  }
 
  // 頂点xとyを同じ集合に入れる
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      if(p[y] < p[x]) swap(x, y);
      p[x] += p[y];
	  p[y] = x;
	  for(auto p: c[y]){
        c[x][p.first] += p.second;
	  }
      return true;
    }
    return false;
  }

  inline int size(int x){
    return -p[get(x)];
  }

  inline int query(int x, int y){
    return c[get(x)][y];
  }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,q;
	cin >> n >> q;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
		c[i]--;
	}
	dsu d(n, c);
	while(q--){
		int op, a, b;
		cin >> op >> a >> b;
		a--, b--;
		if(op == 1){
			d.unite(a, b);
		}else if(op == 2){
			cout << d.query(a, b) << endl;
		}else{
			assert(false);
		}
	}
}
