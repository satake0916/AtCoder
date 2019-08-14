#include "bits/stdc++.h"
using namespace std;

int main() {
    string s;
    cin >> s;
    bool f = false;
    if(s[0] == s[1] && s[2] == s[3]) f = true;
    if(s[0] == s[2] && s[1] == s[3]) f = true;
    if(s[0] == s[3] && s[1] == s[2]) f = true;
    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) f = false;
    cout << (f ? "Yes" : "No") << endl;
}
