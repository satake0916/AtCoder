#include "bits/stdc++.h"
using namespace std;
int INF = numeric_limits<int>::max() / 2;

int n;//頂点数

vector<vector<int> > d(n, vector<int>(n,INF)); 
//グラフの距離を格納した2次元配列（隣接行列）
// d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

void warshall_floyd(){
  for(int i = 0; i < n; i++)      // 経由する頂点
    for(int j = 0; j < n; j++)    // 開始頂点
      for(int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}