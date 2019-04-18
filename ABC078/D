#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n,z,w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) cout << abs(a[0] - w) << endl;
    else cout << max(abs(a[n-1] - w), abs(a[n-2] - a[n-1])) << endl;
}
