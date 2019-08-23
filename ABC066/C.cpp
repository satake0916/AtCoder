#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> d;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(n%2==0){
            if(i%2==0) d.push_back(a);
            else d.push_front(a);
        }else{
            if(i%2==0) d.push_front(a);
            else d.push_back(a);
        }
    }
    for(int i = 0; i < n; i++) cout << d[i] << " ";
    cout << endl;
}
