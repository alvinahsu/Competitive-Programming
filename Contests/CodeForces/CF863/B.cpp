/*
*  File: CF863B
*  Author: Alvin Hsu 
*  Date: 04/04/2023 18:36:29
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
	while(t--) {
		int n,x1,y1,x2,y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;
		x1 = min(x1, n - x1 + 1);
		y1 = min(y1, n - y1 + 1);
		int l1 = min(x1, y1);
		
		x2 = min(x2, n - x2 + 1);
		y2 = min(y2, n - y2 + 1);
		int l2 = min(x2, y2);
		int ans = abs(l1 - l2);
		cout << ans << '\n';
	}
	return 0;	
}
