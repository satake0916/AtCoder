#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int h,w,n;
    cin >> h >> w >> n;
    int sr, sc;
    cin >> sr >> sc;
    sr--; sc--;
    string s,t;
    cin >> s >> t;

    int safe_start = 0, safe_end = w;
    bool r_bool = false;
    for(int i = n-1; i >= 0; i--){
        if(t[i] == 'R'){
            if(safe_start < w-1){
                safe_start--;
                safe_start = max(0,safe_start);
            }
        }else if(t[i] == 'L'){
            if(safe_end > 0){
                safe_end++;
                safe_end = min(w,safe_end);
            }
        }

        if(s[i] == 'R'){
            safe_end--;
            safe_end = max(0, safe_end);
        }else if(s[i] == 'L'){
            safe_start++;
            safe_start = min(w,safe_start);
        }
    }
    if(safe_start <= sc && sc < safe_end) r_bool = true;

    safe_start = 0, safe_end = h;
    bool c_bool = false;
    for(int i = n-1; i >= 0; i--){
        if(t[i] == 'D'){
            if(safe_start < h-1){
                safe_start--;
                safe_start = max(0,safe_start);
            }
        }else if(t[i] == 'U'){
            if(safe_end > 0){
                safe_end++;
                safe_end = min(h,safe_end);
            }
        }

        if(s[i] == 'D'){
            safe_end--;
            safe_end = max(0, safe_end);
        }else if(s[i] == 'U'){
            safe_start++;
            safe_start = min(h,safe_start);
        }
    }
    if(safe_start <= sr && sr < safe_end) c_bool = true;

    cout << ((r_bool && c_bool) ? "YES" : "NO") << endl;
}
