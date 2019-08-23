#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

bool evenstr(string s){
    int n = s.size();
    bool ret = true;
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n/2+i]) ret = false;
    }
    return ret;
}

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i += 2){
        if(evenstr(s.substr(0,i))) ans = i;
    }
    cout << ans << endl;
}
