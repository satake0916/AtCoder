#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    set<string> st, exst;
    for(int i = 0; i < n; i++){
        if(s[i][0] == '!'){
            if(st.find(s[i].substr(1)) == st.end()){
                exst.insert(s[i].substr(1));
            }else{
                cout << s[i].substr(1) << endl;
                return 0;
            }
        }else{
            if(exst.find(s[i]) == exst.end()){
                st.insert(s[i]);
            }else{
                cout << s[i] << endl;
                return 0;
            }
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}
