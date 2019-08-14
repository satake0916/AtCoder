#include "bits/stdc++.h"
using namespace std;

int main() {
    int n,l;
    cin >> n >> l;
    int sum = 0;
    int min = 1000;
    for(int i = 1; i <= n; i++){
        int temp = l + i - 1;
        sum += temp;
        if(abs(temp) < abs(min)) min = temp;
    }
    cout << sum - min << endl;
}
