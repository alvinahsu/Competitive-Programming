/*
*  File: CFEDU147C
*  Author: Alvin Hsu
*  Date: 04/20/2023 22:27:43
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
		string s;
		cin >> s;
		vector<vector<int>> idx(26, {-1});
		for (int i = 0; i < s.size(); i++){
			idx[s[i]-'a'].push_back(i);
		}
		int ans = 1e8;
		for (int i = 0; i < 26; i++){
			idx[i].push_back(s.size());
			int curr = 0;
			for (int j = 1; j < idx[i].size(); j++){
				int diff = idx[i][j] - idx[i][j-1] - 1;
				int k = 0;
				while((1 << k) <= diff){
					k++;
				}
				curr = max(k, curr);
			}
			ans = min(ans, curr);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
