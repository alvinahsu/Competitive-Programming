/*
*  File: CF871E
*  Author: Alvin Hsu
*  Date: 05/06/2023 07:41:20
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int DIRX[] = {0,0,-1,1}, DIRY[] = {1,-1,0,0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<int>>v(n, vector<int>(m));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> v[i][j];
			}
		}
		function<int(int,int)> dfs = [&](int i, int j){
			int sum = v[i][j];
			v[i][j] = 0;
			for (int d = 0; d < 4; d++){
				int newI = DIRY[d] + i;
				int newJ = DIRX[d] + j;
				if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && v[newI][newJ]){
					sum += dfs(newI, newJ);
				}
			}
			return sum;	
		};
		int mx = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (v[i][j]) {
					mx = max(mx, dfs(i,j));
				}
			}
		}
		cout << mx << '\n';
	}
	return 0;
}
