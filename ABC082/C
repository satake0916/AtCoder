#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n;
    map<int, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        int first = itr->first;
        int second = itr->second;
        if(first > second) ans += second;
        else ans += second - first;
    }
    cout << ans << endl;
}
