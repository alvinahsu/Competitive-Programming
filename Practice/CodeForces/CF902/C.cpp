/*
*  File: CF902C
*  Author: Alvin Hsu
*  Date: 11/09/2023 20:49:00
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
		if (k == 1){
			cout << 1 << '\n';
		}
		else if (k == 2){
			cout << min(n,m) + (m-min(n,m))/n << '\n';
		}
		else if (k == 3){
			cout << m - (min(n,m) + (m-min(n,m))/n) << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}
