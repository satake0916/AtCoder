#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> under(n+5, -1);
	vector<int> pile(n+5, 0);

	set<int> st;
	vector<int> ans(n+5, -1);

	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		auto it = st.upper_bound(p);
		if(it == st.end()){
			pile[p] = 1;
			st.insert(p);
		}else{
			under[p] = (*it);
			pile[p] = pile[(*it)]+1;
			st.erase(it);
			st.insert(p);
		}

		if(pile[p] >= k){
			st.erase(p);
			int x = p;
			for(int j = 0; j < k; j++){
				ans[x] = i+1;
				x = under[x];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
}

