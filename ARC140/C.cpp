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

int main(){
	int n,x;
	cin >> n >> x;
	if(n%2 == 1){
		int s = (n+1)/2;
		vector<int> up, down;
		int k = s+1;
		int t = s-1;
		while(k <= n){
			up.pb(k);
			k++;
		}
		while(t >= 1){
			down.pb(t);
			t--;
		}
		if(x == s){
			cout << x << " ";
			for(int i = 0; i < n/2; i++){
				cout << down[i] << " " << up[i] << " ";
			}
		}else if(x < s){
			cout << x << " " << s << " ";
			for(int i = 0, j = 0; i < n/2 || j < n/2; i++, j++){
				cout << up[i] << " ";
				if(x == down[j]) j++;
				if(j < n/2) cout << down[j] << " ";
			}
		}else{
			cout << x << " " << s << " ";
			for(int i = 0, j = 0; i < n/2 || j < n/2; i++, j++){
				cout << down[i] << " ";
				if(x == up[j]) j++;
				if(j < n/2) cout << up[j] << " ";
			}
		}
	}else{
		vector<int> up, down;
		int s = n/2 + 1;
		int t = n/2;
		while(s <= n){
			up.pb(s);
			s++;
		}
		while(t >= 1){
			down.pb(t);
			t--;
		}
		if(x == n/2){
			for(int i = 0; i < n/2; i++){
				cout << down[i] << " " << up[i] << " ";
			}
		}else if(x == (n/2 + 1)){
			for(int i = 0; i < n/2; i++){
				cout << up[i] << " " << down[i] << " ";
			}
		}else if(x > n/2 + 1){
			cout << x << " ";
			for(int i = 0, j = 0; i < n/2 || j < n/2; i++, j++){
				cout << down[i] << " ";
				if(x == up[j]) j++;
				if(j < n/2) cout << up[j] << " ";
			}
		}else{
			cout << x << " ";
			for(int i = 0, j = 0; i < n/2 || j < n/2; i++, j++){
				cout << up[i] << " ";
				if(x == down[j]) j++;
				if(j < n/2) cout << down[j] << " ";
			}
		}
	}
	cout << endl;
}
