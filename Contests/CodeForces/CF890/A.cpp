/*
*  File: CF890A
*  Author: Alvin Hsu
*  Date: 08/05/2023 10:10:43
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
		auto s = v;
		sort(s.begin(), s.end());
		int good = 0;
		for (int i = n-1; i >= 0; i--){
			if (v[i] == s[i]) good++;
			else break;
		}
		if (good == n){
			cout << 0 << '\n';
		}
		else {
			cout << *max_element(v.begin(), v.end()-good) << '\n';
		}
	}
	return 0;
}
