/*
*  File: CF891A
*  Author: Alvin Hsu
*  Date: 08/07/2023 09:56:12
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
		int o = 0, e = 0;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			if (x&1) o++;
			else e++;
		}
		bool ok = o%2==0;
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
	return 0;
}
