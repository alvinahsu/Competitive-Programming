/*
*  File: CF877C
*  Author: Alvin Hsu
*  Date: 06/04/2023 10:10:51
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
		int n,m;
		cin >> n >> m;
		vector<vector<int>> ans(n, vector<int>(m));
		int k = 1;
		for (int i = 0; i < n; i+=2){
			for (int j = 0; j < m; j++){
				ans[i][j] = k++;
			}
		}
		for (int i = 1; i < n; i+=2){
			for (int j = 0; j < m; j++){
				ans[i][j] = k++;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << ans[i][j] << " \n"[j == m-1];
			}
		}
		cout << '\n';
	}
	return 0;
}
