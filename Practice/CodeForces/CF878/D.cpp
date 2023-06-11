/*
*  File: CF878D
*  Author: Alvin Hsu
*  Date: 06/11/2023 10:24:26
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
		vector<int> v(n);
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		auto check = [&](int mx){
			int place = 0;
			for (int i = 0; i < n;){
				place++;
				int upper = v[i] + 2 * mx;
				while(i < n && v[i] <= upper){
					i++;
				}
			}
			return place <= 3;
		};
		int l = 0, r = 1e9;
		while(l < r){
			int m = l + (r - l) / 2;
			if (check(m)){
				r = m;
			}
			else {
				l = m+1;
			}
		}
		cout << l << '\n';
	}
	return 0;
}
