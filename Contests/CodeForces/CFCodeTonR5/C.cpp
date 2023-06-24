/*
*  File: CFCodeTonR5C
*  Author: Alvin Hsu
*  Date: 06/24/2023 09:59:00
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
		vector<int> v(n);
		for (auto &a : v){
			cin >> a;
		}
		vector<vector<int>> last(n+1);
		vector<vector<int>> dp(n+1, vector<int>(2));
		for (int i = 1; i <= n; i++){
			int hasLast = last[v[i-1]].size();
			//don't take
			dp[i][0] = dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
			//do take
			if (hasLast){
				int l = last[v[i-1]].back();
				dp[i][1] = max(dp[i][1], dp[l][1] + (i - l));
				dp[i][1] = max(dp[i][1], dp[l][0] + (i - l) + 1);
			}
			last[v[i-1]].push_back(i);
		}
		
		cout << max(dp[n][0], dp[n][1]) << '\n';
	}
	return 0;
}
