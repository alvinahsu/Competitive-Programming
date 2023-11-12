/*
*  File: CF867C
*  Author: Alvin Hsu
*  Date: 04/24/2023 07:33:46
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
		long long n;
		cin >> n;
		long long ans = n * (n+1) + n + 2;
		cout << ans << '\n';
	}
	return 0;
}
