/*
*  File: CF876D
*  Author: Alvin Hsu
*  Date: 06/03/2023 10:12:28
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int inf = (int)1e9;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//contiguous interval used to move all those elements around
	//dp[i][j] = minimum cost using element up to i, with i not being in an interval and having
	//at most j intervals
	
	//if c[i] < c[i-1], if i-1 was not in an interval (which means it is fixed)
	//dp[i][j] = min(dp[i][j], dp[i-1][j])
	
	//see where the previous interval ends
	//dp[i][j] = min(d[i][j], dp[k][j-1] + j - i - 1)
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>c(n);
		for (auto &a : c){
			cin >> a;
		}
		vector<vector<int>> dp(n+1, vector<int>(n+1, inf));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++){
			//# of intervals we can use
			//it is amost i+1
			for (int k = 0; k <= i; k++){
				//we can just keep static
				if (!i || c[i-1] < c[i]){
					dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
				}
				//create new interval starting with i, and ending at j-1
				for (int j = i+1; j < n; j++){
					if (!i || c[i-1] < c[j]) {
						dp[j+1][k+1] = min(dp[j+1][k+1], dp[i][k] + j - i);
					}
				}
				dp[n][k+1] = min(dp[n][k+1], dp[i][k] + n - i);
			}
		}
		int mn = dp[n][0];
		for (int i = 1; i <= n; i++){
			mn = min(dp[n][i], mn);
			cout << mn << ' ';
		}
		cout << '\n';
	}
	return 0;
}
