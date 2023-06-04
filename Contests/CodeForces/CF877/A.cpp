/*
*  File: CF877A
*  Author: Alvin Hsu
*  Date: 06/04/2023 10:10:51
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
		sort(v.begin(), v.end());
		if (v[0] < 0 || v[0] == v.back()){
			cout << v[0] << '\n';
			continue;
		}
		cout << v.back() << '\n';
		
	}
	return 0;
}
