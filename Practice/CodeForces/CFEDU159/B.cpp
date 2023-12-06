/*
*  File: CFEDU159B
*  Author: Alvin Hsu
*  Date: 12/04/2023 13:44:28
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
	#define int long long
	int tt;
	cin >> tt;
	while(tt--){
		int n,p,l,t;
		cin >> n >> p >> l >> t;
		int open = (n+6) / 7;
		//attends lesson and completes 2 task
		int best = l + 2 * t;
		int takeBest = min((p+best-1) / best, open / 2);
		int ans = n;
		ans -= takeBest;
		p -= (takeBest * best);
		if (open&1 && p > 0){
			p -= (l + t);
			ans--; 
		}
		if (p > 0){
			ans -= ((p+l-1) / l);
		}
		cout << ans << '\n';
	}
	return 0;
}
