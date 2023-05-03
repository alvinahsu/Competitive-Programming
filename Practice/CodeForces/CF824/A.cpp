/*
*  File: CF824A
*  Author: Alvin Hsu
*  Date: 05/02/2023 14:40:02
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
		int ans = (n-3) / 3 - 1;
		cout << ans << '\n';
	}
	return 0;
}
