/*
*  File: UCSDSP23_3B
*  Author: Alvin Hsu
*  Date: 05/01/2023 17:58:30
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
	string s,t;
	cin >> s >> t;
	int ans = t.size();
	for (int i = 0; i < s.size(); i++){
		if (s[i] != t[i]) {
			ans = i+1;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}
