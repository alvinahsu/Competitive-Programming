/*
*  File: CF894D
*  Author: Alvin Hsu
*  Date: 08/24/2023 13:32:25
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
		long long l = 0, r = INT_MAX;
		while(l < r){
			long long m = l + (r - l + 1) / 2;
			long long get = m * (m-1) / 2;
			if (get > n){
				r = m-1;
			}
			else {
				l = m;
			}
		}
		long long get = l * (l-1) / 2;
		assert(n - get <= l);
		cout << l + (n - get) << '\n';
	}
	return 0;
}
