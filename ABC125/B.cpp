#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int main(){
    int n;
    cin >> n;
    vector<int> v(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i] - c[i] > 0) ans += v[i] - c[i];
    }
    cout << ans << endl;
}
