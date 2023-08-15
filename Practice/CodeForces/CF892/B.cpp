/*
*  File: CF892B
*  Author: Alvin Hsu
*  Date: 08/14/2023 16:36:22
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
		vector<vector<long long>> v(n);
		for (auto &a : v){
			int x;
			cin >> x;
			for (int i = 0; i < x; i++){
				int m;
				cin >> m;
				a.push_back(m);
			}
			sort(a.begin(), a.end());
		}
		long long ans = 0;
		long long mn = 1e18;
		long long tot = 0;
		for (int i = 0; i < n; i++){
			if (v[i].size() == 1) ans += v[i][0];
			else {
				mn = min(v[i][0], mn);
				ans += v[i][1];
			}
		}
		for (int i = 0; i < n; i++){
			long long curr = ans;
			if (v[i].size() == 1) curr -= v[i][0];
			else {
				curr -= v[i][1];
			}
			curr += mn;
			tot = max(tot,curr);
		}
		cout << tot << '\n';
	}
	return 0;
}
