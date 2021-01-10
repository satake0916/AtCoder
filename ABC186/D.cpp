#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> pos, neg;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a > 0) pos.push_back(a);
        else neg.push_back(a);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    long long npos = pos.size();
    long long nneg = neg.size();
    
    vector<long long> sum_pos, sum_neg;
    sum_pos.push_back(0);
    sum_neg.push_back(0);
    for(int i = 0; i < npos; i++){
        sum_pos.push_back(pos[i] + sum_pos[i]);
    }
    for(int i = 0; i < nneg; i++){
        sum_neg.push_back(neg[i] + sum_neg[i]);
    }

    long long sum = 0;

    for(int i = 0; i < npos; i++){
        sum += sum_pos[npos] - sum_pos[i] - (npos - i) * pos[i];
    }

    for(int i = 0; i < nneg; i++){
        sum += sum_neg[nneg] - sum_neg[i] - (nneg - i) * neg[i];
        sum += sum_pos[npos] - neg[i] * npos;
    }

    cout << sum << endl;
}
