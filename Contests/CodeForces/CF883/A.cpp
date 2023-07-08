/*
*  File: CF883A
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
		int n;
		cin >> n;
		int ans = 0;
		while(n--){
			int a,b;
			cin >> a >> b;
			if (a > b) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
