/*
*  File: CFCodeTonR4B
*  Author: Alvin Hsu
*  Date: 05/04/2023 16:48:24
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if (n%2 == 0){
			cout << "-1" << '\n';
			continue;
		}
		vector<int> ans;
		while(n > 1){
			if (((n+1) / 2)&1) {
				ans.push_back(1);
				n = (n+1) / 2;
			}
			else {
				assert((((n-1)/2)&1) == 1);
				ans.push_back(2);
				n = (n-1) / 2;
			}
		}
		cout << ans.size() << '\n';
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << " \n"[i == ans.size()-1];
		}
	}
	return 0;	
}
