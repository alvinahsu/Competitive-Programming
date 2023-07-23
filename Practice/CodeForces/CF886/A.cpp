/*
*  File: CF886A
*  Author: Alvin Hsu
*  Date: 07/23/2023 15:07:49
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
		vector<int>v(3);
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		bool ok = v[1] + v[2] >= 10;
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
