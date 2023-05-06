/*
*  File: CF871B
*  Author: Alvin Hsu
*  Date: 05/06/2023 07:33:44
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
		int mx = 0, curr = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] == 1) {
				curr = 0;
			}
			else {
				curr++;
				mx = max(mx, curr);
			}
		}
		cout << mx << '\n';
	}
	return 0;
}
