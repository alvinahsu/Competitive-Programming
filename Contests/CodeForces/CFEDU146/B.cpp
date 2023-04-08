/*
*  File: CFEDU146B
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
		int a,b;
		cin >> a >> b;
		int ans = 1e9;
		for (int i = 0; i <= 200000; i++){
			ans = min(ans, i + ((a + (i+1) - 1) / (i+1)) + ((b + (i+1) - 1) / (i+1)));
		}
		cout << ans << '\n';
	}
	return 0;	
}
