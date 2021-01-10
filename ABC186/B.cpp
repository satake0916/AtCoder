#include "bits/stdc++.h"
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    int sum = 0;
    int minimum = 100;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int t;
            cin >> t;
            sum += t;
            minimum = min(t, minimum);
        }
    }
    cout << sum - minimum * h * w << endl;
}
