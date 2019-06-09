#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int p,q,r;
    cin >> p >> q >> r;
    cout << p + q + r - max(p,max(q,r)) << endl;
}
