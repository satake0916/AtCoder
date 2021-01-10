#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int t = i;
        bool f = false;
        while(t > 0){
            if(t % 10 == 7){
                f = true;
                break;
            }else{
                t /= 10;
            }
        }
        t = i;
        while(t > 0){
            if(t % 8 == 7){
                f = true;
                break;
            }else{
                t /= 8;
            }
        }
        if(f) ans++;
    }
    cout << n - ans << endl;
}
