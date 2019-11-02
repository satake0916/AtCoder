#include "bits/stdc++.h"
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    bool f = 1 <= a && a <= 9 && b <= 9 && 1 <= b;
    cout << (f ? a*b : -1) << endl;
}
