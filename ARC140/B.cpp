#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>

using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

int check(string s, int index){
	assert(s[index] == 'R');
	int cnt = 0;
	int n = s.size();
	int l = index;
	int r = index;
	l--, r++;
	while(0 <= l && r < n){
		if(s[l] == 'A' && s[r] == 'C'){
			cnt++;
			l--, r++;
		}else{
			break;
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int anytime = 0;
	priority_queue<int> q;
	for(int i = 0; i < n; i++){
		if(s[i] == 'R'){
			int t = check(s, i);
			if(t == 0) continue;
			if(t == 1) anytime++;
			else q.push(t);
		}
	}
	int cnt = 0;
	while(1){
		{
			if(q.empty()){
				if(anytime == 0){
					break;
				}else{
					anytime--;
				}
			}else{
				int nxt = q.top();
				q.pop();
				nxt--;
				if(nxt == 1) anytime++;
				else q.push(nxt);
			}
			cnt++;
		}
		
		{
			if(anytime > 0){
				anytime--;
			}else{
				if(q.empty()){
					break;
				}else{
					q.pop();
				}
			}
			cnt++;
		}
	}

	cout << cnt << endl;
}
