/*
*  File: CFEDU151B
*  Author: Alvin Hsu
*  Date: 07/01/2023 14:46:01
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
		int xa,ya,xb,yb,xc,yc;
		cin>>xa>>ya>>xb>>yb>>xc>>yc;
		int ans = 0;
		if (xa <= min(xb,xc)){
			ans += min(xb,xc) - xa;
		}
		if (xa >= max(xb, xc)){
			ans += xa - max(xb,xc);
		}
		if (ya >= max(yb,yc)){
			ans += ya - max(yb,yc);
		}
		if (ya <= min(yb,yc)){
			ans += min(yb,yc) - ya;
		}
		cout << ans+1 << '\n';
	}
	return 0;
}
