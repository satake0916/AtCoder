#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> black(n,0);
    if(s[0] == '#') black[0] = 1;
    for(int i = 1; i < n; i++){
        black[i] = black[i-1];
        if(s[i] == '#') black[i]++;
    }
    int ans = n - black[n-1];
    for(int i = 0; i < n; i++){
        int temp = black[i] + ((n-1-i) - (black[n-1] - black[i]));
        ans = min(ans, temp);
    }
    cout << ans << endl;
}
