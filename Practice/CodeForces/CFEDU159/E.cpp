/*
*  File: CFEDU159E
*  Author: Alvin Hsu
*  Date: 12/04/2023 13:44:28
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
	int n;
	cin >> n;
	vector<string> v(n);
	int mxLevel = 0;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		mxLevel = max(mxLevel, (int)v[i].size());
	}
	map<array<int,3>, int> cnt;
	vector<vector<vector<int>>> dp(mxLevel+1, vector<vector<int>>(27, vector<int>(27)));		
	for (int i = 0; i < n; i++){
		string curr = v[i];
		reverse(curr.begin(), curr.end());
		int last = 26;
		for (int j = 1; j <= curr.size(); j++){
			int c = curr[j-1]-'a';
			dp[j][c][last] += (curr.size() - j);
			cnt[{j,c,last}]++;
			last = c;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		int last = 26;
		for (int j = 1; j <= v[i].size(); j++){
			int c = v[i][j-1]-'a';
			ans += (v[i].size()-j)*cnt[{j,c,last}] + dp[j][c][last];
			dbg(cnt[{j,c,last}]);
			last = c;
		}
	}
	cout << ans << '\n';
	return 0;
}
