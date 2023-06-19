/*
*  File: CF879B
*  Author: Alvin Hsu
*  Date: 06/19/2023 13:38:36
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
		string l,r;
		cin >> l >> r;
		while(l.size() != r.size()) l = "0" + l;
		int n = r.size();
		assert(n == l.size());
		int ans = 0;
		int i = 0;
		while(i < n && l[i] == r[i]) i++;
		if (i < n) ans += (abs(l[i] - r[i]));
		i++;
		while(i < n) i++,ans += 9;
		cout << ans << '\n';
	}
	return 0;
}
