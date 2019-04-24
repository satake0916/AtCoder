#include "bits/stdc++.h"
using namespace std;
int INF = numeric_limits<int>::max() / 2;

int n,m;//nは頂点数、mは辺の数
vector<pair<int, int> > edge;//edge[i](first, second) i番目の辺はfirst->second
vector<int> weight;//weight[i] i番目の辺の重み
vector<int> d(1010,INF);//各頂点の始点からの最短距離。INFで初期化してある
vector<bool> negative(1010, false);//負の閉路チェック用のbool配列

void bellmanford(int start){
    d[start] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            auto p = edge[j];
            if(d[p.second] > d[p.first] + weight[j]){
                d[p.second] = d[p.first] + weight[j];
            }
        }
    }
}

//この関数を実行後negative[n-1]がtrueになっていたら閉路が存在する
void boolbellmanford(int start){
    d[start] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            auto p = edge[j];
            if(d[p.first] == INF) continue;
            if(d[p.second] > d[p.first] + weight[j]){
                d[p.second] = d[p.first] + weight[j];
                negative[p.second] = true;
            }
            if(negative[p.first]) negative[p.second] = true;
        }
    }
}