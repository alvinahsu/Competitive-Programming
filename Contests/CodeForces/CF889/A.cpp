/*
*  File: CF889A
*  Author: Alvin Hsu
*  Date: 07/29/2023 09:42:17
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
		int ans = 0;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			ans += x == i;
		}
		cout << (ans+1)/2 << '\n';
	}
	return 0;
}
