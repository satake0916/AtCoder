#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int np = n;
    int m = 0;
    while(np != 0){
        m += np%10;
        np /= 10;
    }
    bool f = n%m == 0;
    cout << (f ? "Yes" : "No") << endl;
}
