#include "bits/stdc++.h"
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    long long ans = 0;
    vector<long long> rec;
    char last = s[0];
    long long num = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == last){
            num++;
        }else{
            rec.push_back(num);
            num = 1;
            last = s[i];
        }
    }
    rec.push_back(num);

    if(rec.size() == 1){
        cout << rec[0] * k / 2 << endl;
        return 0;
    }

    for(int t : rec) ans += t/2;
    ans *= k;

    if(s[0] == s[n-1]){
        long long a = rec[0];
        long long b = rec[rec.size()-1];
        ans -= (k-1) * (a/2 + b/2 - (a+b)/2);
    }

    cout << ans << endl;
}
