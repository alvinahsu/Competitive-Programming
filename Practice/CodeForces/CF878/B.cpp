/*
*  File: CF878B
*  Author: Alvin Hsu
*  Date: 06/11/2023 10:24:26
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
		int n, k;
		cin >> n >> k;
		int upper = 1 << min(30, k);
		cout << min(n+1, upper) << '\n';
	}
	return 0;	
}
