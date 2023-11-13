/*
*  File: CF899B
*  Author: Alvin Hsu
*  Date: 11/12/2023 20:02:28
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
		vector<set<int>> v(n);
		set<int> tot;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			for (int j = 0; j < x; j++){
				int s;
				cin >> s;
				v[i].insert(s);
				tot.insert(s);
			}
		}
		int ans = 0;
		for (auto &rem : tot){
			set<int> curr;
			for (int i = 0; i < n; i++){
				if (v[i].find(rem) == v[i].end()){
					for (auto &include : v[i]){
						curr.insert(include);
					}
				}
			}
			ans = max(ans, (int)curr.size());
		}
		cout << ans << '\n';
		
	}
	return 0;
}
