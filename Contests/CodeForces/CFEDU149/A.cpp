/*
*  File: CFEDU149A
*  Author: Alvin Hsu
*  Date: 05/25/2023 07:22:49
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
		int x,k;
		cin >> x >> k;
		if (x%k == 0){
			cout << 2 << '\n';
			assert((x-1)%k != 0);
			cout << 1 << " " <<  x-1 << '\n';
		}
		else {
			cout << 1 << '\n';
			cout << x << '\n';
		}
	}
	return 0;
}
