#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    bool f = false;
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            if(i * j == n) f = true;
        }
    }
    cout << (f ? "Yes" : "No") << endl;
}
