/*
*  File: UCSDSP23_1A
*  Author: Alvin Hsu
*  Date: 04/18/2023 09:15:04
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool ok = true;
	for (int i = 1; i < n; i++){
		ok &= (s[i] != s[i-1]);
	}
	cout << (ok ? "Yes" : "No") << '\n';
	return 0;
}
