/*
*  File: GORAC
*  Author: Alvin Hsu
*  Date: 15/04/2023 21:08:25
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
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++){
		int n;
		cin >> n;
		vector<int>v(n);
		int c = 1;
		map<int,int> m;
		for (auto &a : v){
			cin >> a;
		}
		bool ok = true;
		int last = -1;
		set<pair<int,int>> ans;
		for (auto &a : v){
			if (m.find(a) == m.end()){
				m[a] = c;
				ans.insert({c, a});
				c++;
			}
			else {
				ok &= (m[a] >= last);
			}
			last = m[a];
		}
		cout << "Case #" << t << ": ";
		if (!ok){
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			for (auto &a : ans){
				cout << a.second << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}
