#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

vector<vector<pair<int, int> > > edge;//edge[i][j] firstがiからj番目のノード、secondがその重み
vector<vector<int> >d(2, vector<int>(100010,INF));

void dijkstra(int start, int num){
    priority_queue<int, vector<int>, greater<int> > q;

    d[num][start] = 0;
    q.push(start);

    while(!q.empty()){
        int now = q.top();
        q.pop();
        for(int j = 0; j < edge[now].size(); j++){
            int next = edge[now][j].first;
            int nextd = d[num][now] + edge[now][j].second;
            if(nextd < d[num][next]){
                d[num][next] = nextd;
                q.push(next);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    edge.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(make_pair(b,1));
        edge[b].push_back(make_pair(a,1));
    }
    dijkstra(0,0);
    dijkstra(n-1,1);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > firstq, secondq;
    for(auto p : edge[0]) firstq.push(make_pair(d[1][p.first], p.first));
    for(auto p : edge[n-1]) secondq.push(make_pair(d[0][p.first], p.first));

    vector<bool> used(n,false);
    used[0] = true;
    used[n-1] = true;
    
    while(1){
        //先行
        int next = -1;
        while(true){
            if(firstq.empty()){
                cout << "Snuke" << endl;
                return 0;
            }
            auto p = firstq.top();
            firstq.pop();
            next = p.second;
            if(!used[next]){
                used[next] = true;
                break;
            }
        }
        for(auto s : edge[next]){
            firstq.push(make_pair(d[1][s.first], s.first));
        }

        //後攻
        while(true){
            if(secondq.empty()){
                cout << "Fennec" << endl;
                return 0;
            }
            auto p = secondq.top();
            secondq.pop();
            next = p.second;
            if(!used[next]){
                used[next] = true;
                break;
            }
        }
        for(auto s : edge[next]){
            secondq.push(make_pair(d[0][s.first], s.first));
        }
    }
}
