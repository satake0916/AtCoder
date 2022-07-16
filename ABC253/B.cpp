#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int h, w;
	cin >> h >> w;
	int px=-1, py=-1;
	int ans = 0;
	for(int i = 0; i < h; i++){
		string s;
		cin >> s;
		for(int j = 0; j < w; j++){
			if(s[j] == 'o'){
				if(px == -1){
					px = i;
					py = j;
				}else{
					ans = abs(px - i)+ abs(py - j);
				}
			}
		}
	}

	cout << ans << endl;
}
