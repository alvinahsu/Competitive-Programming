/*
*  File: CFCodeTonR5B
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
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		vector<int> a(n), b(n), c(n);
		for (auto &it : a) cin >> it;
		for (auto &it : b) cin >> it;
		for (auto &it : c) cin >> it;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		reverse(c.begin(), c.end());
		auto valid = [&](int curr){
			bool ok = true;
			for (int i = 0; i < 32; i++){
				if ((curr&(1 << i)) > 0) {
					ok &= ((x&(1 << i)) > 0);
				}
			}
			return ok;
		};
		int curr = 0;
		for (int i = 0; i < n; i++){
			if (a.size()) {
				if (valid(curr|a.back())) {
					curr |= a.back();
					a.pop_back();
				}
			}
			if (b.size()) {
				if (valid(curr|b.back())) {
					curr |= b.back();
					b.pop_back();
				}
			}
			if (c.size()) {
				if (valid(curr|c.back())) {
					curr |= c.back();
					c.pop_back();
				}
			}
		}
		cout << (curr == x ? "YES" : "NO") << '\n';
	}
	return 0;
}
