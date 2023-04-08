/*
*  File: CFEDU146A
*  Author: Alvin Hsu
*  Date: 06/04/2023 22:28:44
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
		long long k,n;
		cin >> n >> k;
		//n - k*y = multiple of 2
		bool ok = n%2==0 || (k&1 && k <= n);
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;	
}
