/*
*  File: CF912B
*  Author: Alvin Hsu
*  Date: 11/30/2023 08:28:47
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
		vector<vector<int>> v(n, vector<int>(n));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> v[i][j];
			}
		}
		vector<int> ans(n);
		for (int i = 0; i < n; i++){
			int curr = (1 << 30) - 1;
			for (int j = 0; j < n; j++){
				if (i == j) continue;
				if (curr == -1) curr = v[i][j];
				curr &= v[i][j];
			}
			ans[i] = curr;
		}
		bool ok = true;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j) continue;
				ok &= ((ans[i]|ans[j]) == v[i][j]);
			}
		}
		if (ok){
			cout << "YES" << '\n';
			for (int i = 0; i < n; i++){
				cout << ans[i] << " \n"[i == n-1];
			}
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
