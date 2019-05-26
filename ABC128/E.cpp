#include "bits/stdc++.h"
using namespace std;

struct node {
    int time, point, kind;
    bool operator<(const node &p) const {
        return time < p.time;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<node> v;
    for (int i = 0; i < n; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        v.push_back({ s - x, x, 1 });
        v.push_back({ t - x, x, 0 });
    }
    sort(v.rbegin(), v.rend());
    multiset<int> sp;
    for(int i = 0; i < q; i++) {
        int d;
        cin >> d;
        while (!v.empty() && v.back().time <= d) {
            if (v.back().kind) sp.insert(v.back().point);
            else sp.erase(sp.find(v.back().point));
            v.pop_back();
        }
        cout << (sp.empty() ? -1 : *sp.begin()) << '\n';
    }
}
