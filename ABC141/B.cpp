#include "bits/stdc++.h"
using namespace std;
 
int main() {
    string s;
    cin >> s;
    string odd = "RUD", even = "LUD";
    int n = s.size();
    for(int i = 0; i < n; i++){
        bool t = true;
        if(i%2 == 0){
            if(s[i] == 'L') t = false;
        }else{
            if(s[i] == 'R') t = false;
        }
        if(!t){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
