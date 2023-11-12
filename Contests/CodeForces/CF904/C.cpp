/*
*  File: CF904C
*  Author: Alvin Hsu
*  Date: 10/21/2023 22:46:09
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
		vector<pair<int,int>> v;
		vector<pair<int,int>> org;
		for (int i = 0; i < n; i++){
			int l,r;
			cin >> l >> r;
			org.push_back({l,r});
			v.push_back({l,1});
			v.push_back({r+1,-1});
		}
		sort(v.begin(), v.end());
		int active = 0, at = -1;
		int ans = 0, mn = 1e9;
		for (int i = 0; i < v.size(); i++){
			if (v[i].second == -1){
				active--;
			}
			else {
				active++;
				if (active > ans){
					ans = active;
					at = v[i].first;
				}
			}
		}
		vector<pair<int,int>> newV;
		for (auto [l,r] : org){
			if (l <= at && at <= r){
				newV.push_back({l,1});
				newV.push_back({r+1,-1});
			}
		}
		sort(newV.begin(), newV.end());
		for (int i = 0; i < newV.size(); i++){
			if (newV[i].second == -1){
				active--;
				if (newV[i].first <= m){
					mn = min(mn, active);
				}
			}
			else {
				active++;
				assert(i+1 < newV.size());
				if (newV[i].first != newV[i+1].first){
					mn = min(mn, active);
				}
			}
		}
		if (newV[0].first > 1 || newV.back().first <= m) mn = 0;
		dbg(mn);
		cout << ans - mn << '\n';
	}
	return 0;
}
