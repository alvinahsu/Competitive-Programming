/*
*  File: CF878F
*  Author: Alvin Hsu
*  Date: 06/11/2023 11:54:39
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
	//dp[i][j][k] = if possible to reach (i,j) if we have to stand still nore more than k times
	int t;
	cin >> t;
	while(t--){
		int n,m,r;
		cin >> n >> m >> r;
		map<int,set<int>> X, Y;
		vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(r+1)));
		for (int i = 0; i < r; i++){
			int time, d, coord;
			cin  >> time >> d >> coord;
			//horizontal (X)
			if (d == 1){
				X[time].insert(coord);
			}
			//vertical(Y)
			else {
				Y[time].insert(coord);
			}
		}
		dp[0][0][0] = 1;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){
				for (int k = 0; k <= r; k++){
					int currT = i + j + k;
					bool invalid = X[currT].count(i) || Y[currT].count(j);
					if (!invalid){
						if (k){
							dp[i][j][k] |= dp[i][j][k-1];
						}
						if (i){
							dp[i][j][k] |= dp[i-1][j][k];
						}
						if (j){
							dp[i][j][k] |= dp[i][j-1][k];
						}
					}
				}
			}
		}
		int ans = -1;
		for (int i = r; i >= 0; i--){
			if (dp[n][m][i]){
				ans = n + m + i;
			}
		}
		cout << ans << '\n';
		
	}
	return 0;
}
