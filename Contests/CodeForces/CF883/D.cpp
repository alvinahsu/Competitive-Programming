/*
*  File: CF883D
*  Author: Alvin Hsu
*  Date: 07/07/2023 10:32:34
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
		long double n,d,h;
		cin >> n >> d >> h;
		long double factor = d / h;
		vector<int> y(n);
		for (auto &a : y){
			cin >> a;
		}
		long double ans = 0;
		for (int i = 0; i < n; i++){
			ans += factor * h * h;
			if (i + 1 < n && y[i]+h>y[i+1]){
				long double diff = y[i]+h-y[i+1];
				ans -= factor * diff * diff;
			}
		}
		cout << fixed << setprecision(15) << ans/2 << '\n';
	}
	return 0;
}
