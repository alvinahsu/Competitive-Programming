/*
*  File: CF874C
*  Author: Alvin Hsu
*  Date: 05/19/2023 07:31:18
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
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		bool ans = false;
		multiset<int>par[2];
		for (int j = 0; j < n; j++){
			auto &curr = par[v[j]&1];
			curr.insert(v[j]);
		}
		for (int i = 0; i < 2; i++){
			bool ok = true;
			for (int j = 0; j < n; j++){
				auto &curr = par[v[j]&1];
				if ((v[j]&1) == i) continue;
				auto &op = par[!(v[j]&1)];
				auto it = !i ? curr.lower_bound(v[j]) : op.lower_bound(v[j]);
				auto check = !i ? curr.begin() : op.begin();
				if (it == check){
					ok = false;
				}
			}
			ans |= ok;
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}
