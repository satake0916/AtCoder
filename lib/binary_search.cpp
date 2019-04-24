#include <iostream>
#include <vector>
using namespace std;

const int n;
vector<int> a(n);

// index が条件を満たすかどうか。主にここを書き換える。
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1。最終的にはぎりぎり満たさないやつになる。
    int ok = n; // 「index = n-1」が条件を満たさないこともあるので、初期値はn。最終的にはぎりぎり満たすやつになる。

    /* ok と ng のどちらが大きいかわからないことを考慮するならabsをつける */
    while ((ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}