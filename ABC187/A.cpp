#include "bits/stdc++.h"
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    cout << max((a[0]-'0')+(a[1]-'0') + (a[2]-'0'), (b[0]-'0') + (b[1]-'0') + (b[2]-'0')) << endl;
}
