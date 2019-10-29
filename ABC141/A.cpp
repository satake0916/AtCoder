#include "bits/stdc++.h"
using namespace std;
 
int main() {
    string w[] = {"Sunny", "Cloudy", "Rainy"};
    string s;
    cin >> s;
    for(int i = 0; i < 3; i++){
        if(s == w[i]) cout << w[(i+1)%3] << endl;
    }
}
