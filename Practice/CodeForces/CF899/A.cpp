/*
*  File: CF899A
*  Author: Alvin Hsu
*  Date: 11/12/2023 20:02:28
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
		int n;
		cin >> n;
		int ans = 1;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			if (ans != x){
				ans++;
			}
			else {
				ans += 2;
			}
		}
		cout << ans-1 << '\n';
	}
	return 0;
}
