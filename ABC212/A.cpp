#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a,b;
	cin >> a >> b;
	if(a == 0){
		cout << "Silver" << endl;
	}else if(b == 0){
		cout << "Gold" << endl;
	}else{
		cout << "Alloy" << endl;
	}
}
