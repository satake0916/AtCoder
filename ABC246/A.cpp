#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int x[2][3];
	for(int i = 0; i < 3; i++) cin >> x[0][i] >> x[1][i];

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			if(x[i][j] == x[i][(j+1) % 3]){
				cout << x[i][(j+2) % 3] << " ";
			}
		}
	}
	cout << endl;
}
