/*
*  File: CFCodeTonR5D
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
	int n,m;
	cin >> n >> m;
	string ans(n, '1');
	ans[n-1] = '0';
	map<pair<long long,long long>, long long> mp;
	for (int i = 0; i < m; i++){
		int u,v,y;
		cin >> u >> v >> y;
		u--, v--;
		mp[{u,v}] = y;
	}
	vector<pair<string, int>> res;
	map<pair<int,int>, int> cnt;
	long long tot = 0;
	while(true){
		long long mn = 1e18;
		for (auto &[p,y] : mp){
			int i = p.first, j = p.second;
			int c = cnt[{i,j}];
			if ((ans[i] == '1' && ans[j] == '0') || (ans[i] == '0' && ans[j] == '1')) {
				assert(y >= c);
				//get the max offset (min)
				mn = min(mn, y - c);				
			}
		}
		// dbg(ans,mn);
		tot += mn;
		if (mn == 1e18){
			cout << "inf" << '\n';
			return 0;
		}
		res.push_back({ans, mn});
		vector<pair<int,int>> er;
		for (auto &[p,y] : mp){
			int i = p.first, j = p.second;
			int &c = cnt[{i,j}];
			if ((ans[i] == '1' && ans[j] == '0') || (ans[i] == '0' && ans[j] == '1')) {
				if (ans[i] == '1' && i == 0) {
					if (c + mn <= y) {
						c += mn;
						continue;
					}
				}
				c += mn;
				assert(c <= y && i != 0);
				if (c == y) {
					er.push_back(p);
				}
			}
		}
		//no updates remaining
		if (er.empty()) break;
		for (auto &p : er){
			int i = p.first, j = p.second;
			if (ans[i] == '1') ans[i] = '0';
			else ans[j] = '0';
			mp.erase(mp.find(p));
		}
	}
	cout << tot << " " << res.size() << '\n';
	for (auto &a : res){
		cout << a.first << " " << a.second << '\n';
	}
	return 0;
}
