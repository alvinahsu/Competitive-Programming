/*
*  File: CF870C
*  Author: Alvin Hsu
*  Date: 05/05/2023 07:28:53
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
		int n,m;
		cin >> n >> m;
		bool ok = n > m || n == 1;
		for (int i = 2; 1ll*i*i <= n; i++){
			if (n%i == 0){
				if (i <= m) ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}