/*
*  File: CF818A
*  Author: Alvin Hsu
*  Date: 04/28/2023 08:06:22
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
		int ans = n + (n / 2) * 2 + (n / 3) * 2;
		cout << ans << '\n';
	}
	return 0;
}
