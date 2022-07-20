#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

class UnionFind
{
    std::vector<int > data;

  public:
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                std::swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool find(int x, int y)
    {
        return root(x) == root(y);
    }
    int root(int x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    ll size(int x)
    {
        return -data[root(x)];
    }
};

int main(){
	int h,w;
	cin >> h >> w;
	UnionFind uf = UnionFind(h*w);
	vector<vector<int> > area(h+2, vector<int>(w+2));
	int q;
	cin >> q;
	int difx[4] = {-1, 0, 0, 1};
	int dify[4] = {0, -1, 1, 0};
	rep(i, 0, q){
		int t;
		cin >> t;
		if(t == 1){
			int r,c;
			cin >> r >> c;
			area[r][c] = 1;
			rep(j, 0, 4){
				if(area[r+difx[j]][c+dify[j]] == 1){
					int hoge = (r-1)*w + (c-1);
					int fuga = (r+difx[j]-1)*w + (c+dify[j]-1);
					uf.unite(hoge, fuga);
				}
			}
		}else{
			int ra, ca, rb, cb;
			cin >> ra >> ca >> rb >> cb;
			bool f = (area[ra][ca] == 1) && (area[rb][cb] == 1);
			int hoge = (ra-1)*w + (ca-1);
			int fuga = (rb-1)*w + (cb-1);
			f &= uf.find(hoge, fuga);
			cout << (f ? "Yes" : "No") << endl;
		}
	}
}
