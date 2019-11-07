#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size()+1;
    vector<int> a(n);
    int last = 0;
    a[0] = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == '<'){
            last++;
            a[i+1] = last;
        }else{
            last = 0;
        }
    }
    last = 0;

    for(int i = n-2; i >= 0; i--){
        if(s[i] == '>'){
            last++;
            a[i] = max(a[i], last);
        }else{
            last = 0;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) ans += a[i];
    
    cout << ans << endl;
}
