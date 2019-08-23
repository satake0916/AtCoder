#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
    long long k;
    cin >> k;
    int n = 50;
    cout << n << endl;
    vector<long long> ret(n);
    for(int i = 0; i < n; i++) ret[i] = i;
    long long s = k / n;
    int r = k % n;
    for(int i = 0; i < n; i++) ret[i] += s;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < n; j++){
            if(i == j) ret[j] += n;
            else ret[j]--;
        }
    }
    for(int i = 0; i < n; i++) cout << ret[i] << " ";
    cout << endl;
}
