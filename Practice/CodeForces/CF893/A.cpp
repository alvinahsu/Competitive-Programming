/*
*  File: CF893A
*  Author: Alvin Hsu
*  Date: 08/15/2023 16:30:02
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
		int a,b,c;
		cin >> a >> b >> c;
		bool first = true;
		if (c&1) first = false;
		if (first){
			cout << (a > b ? "First" : "Second") << '\n';
		}
		else {
			cout << (b > a ? "Second" : "First") << '\n';
		}
	}
	return 0;
}
