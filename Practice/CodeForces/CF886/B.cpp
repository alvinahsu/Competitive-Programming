/*
*  File: CF886B
*  Author: Alvin Hsu
*  Date: 07/23/2023 15:07:49
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
		int mx = 0, ans = 0;
		for (int i = 0; i < n; i++){
			int a,b;
			cin >> a >> b;
			if (b > mx && a <= 10) {
				mx = b;
				ans = i+1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
