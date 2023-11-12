/*
*  File: CF885A
*  Author: Alvin Hsu
*  Date: 07/16/2023 10:04:19
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
		int n,m,k;
		cin >> n >> m >> k;
		int x,y;
		cin >> x >> y;
		bool ok = true;
		while(k--){
			int xx,yy;
			cin >> xx >> yy;
			if ((x+y)%2 == (xx+yy)%2) ok = false;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
