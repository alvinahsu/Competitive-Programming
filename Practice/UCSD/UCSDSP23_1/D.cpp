/*
*  File: UCSDSP23_1D
*  Author: Alvin Hsu
*  Date: 04/18/2023 09:15:04
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
	long long n,m;
	cin >> n >> m;
	long long ans = (long long)1e18;
	for (long long i = 1; i <= sqrt((long long)1e16); i++){
		if (i >= 1 && i <= n) {
			long long op = (m+i-1) / i;
			if (op >= 1 && op <= n){
				ans = min(ans, op*i);
			}
		}
		else {
			break;
		}
	}
	cout << (ans == (long long)1e18 ? -1 : ans) << '\n';
	return 0;
}