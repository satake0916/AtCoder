#include "bits/stdc++.h"
using namespace std;

struct segtree{
  vector<int> v;
  int n;
 
  segtree(int i){
    n =1;
    while(i>n)n<<=1;
    v = vector<int>(n<<1);
  }
 
  void add(int i, int x){
    i+=n;
    while(i)
    {
      v[i] = max(x,v[i]);
      i >>=1;
    }
  }
 
  int getvmax(int a, int b, int i=1, int l=0, int r=-2){
    if(r==-2) r=n;
    if(a<=l and r<=b) return v[i];
    int res =0;
    int c=(l+r)>>1;
    if(a<c) res = max(res, getvmax(a,b,i<<1,l,c));
    if(c<b) res = max(res, getvmax(a,b,i<<1|1,c,r));
    return res;
  }
};