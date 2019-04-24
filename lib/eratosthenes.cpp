#include "bits/stdc++.h"
using namespace std;

vector<int> Eratosthenes(int n){
    bool dp[n]; //falseなら素数
    for(int i = 0; i < n; i++) dp[i] = false;
    dp[0] = dp[1] = true;
    vector<int> prime;
    for(int i = 2; i < n; i++){
        if(dp[i]) continue;
        prime.push_back(i);
        for(int j = i * 2; j < n; j += i){
            dp[j] = true;
        }
    }

    return prime;
}