/*
*  File: CF866D
*  Author: Alvin Hsu
*  Date: 15/04/2023 17:01:56
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
		vector<long long>a(n), b(n);
		long long s = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			s += a[i] * b[i];
		}
		vector<pair<long long,long long>> pos;
		long long ma = *max_element(a.begin(), a.end());
		long long mb = *max_element(b.begin(), b.end());
		if (s%ma == 0){
			pos.emplace_back(ma, s/ma);
		}
		if (s%mb == 0) {
			pos.emplace_back(s/mb, mb);
		}
		set<pair<long long, long long>> ans;
		for (auto &p : pos){
			multiset<pair<long long, long long>> msa, msb;
			for (int i = 0; i < n; i++){
				msa.insert({a[i], b[i]});
				msb.insert({b[i], a[i]});
			}
			long long h = p.first, w = p.second;
			bool ok = true;
			for (int i = 0; i < n; i++){
				//bunch by H
				if (msa.size()){
					auto it = --msa.end();
					if (it -> first == h){
						w -= it->second;
						msb.erase(msb.find({it->second, it->first}));
						msa.erase(it);
						continue;
					}
				}
				//bunch by W
				if (msb.size()){
					auto it = --msb.end();
					if (it -> first == w){
						h -= it->second;
						msa.erase(msa.find({it->second, it->first}));
						msb.erase(it);
						continue;
					}
				}
				ok = false;
			}
			if (ok){
				ans.insert(p);
			}
		}
		cout << ans.size() << '\n';
		for (auto &aa : ans){
			cout << aa.first << " " << aa.second << '\n';
		}
	}
	return 0;
}
