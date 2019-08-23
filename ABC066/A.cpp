#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << a + b + c - max(max(a,b), c) << endl;
}
