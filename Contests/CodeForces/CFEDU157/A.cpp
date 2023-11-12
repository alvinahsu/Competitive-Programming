/*
*  File: CFEDU157A
*  Author: Alvin Hsu
*  Date: 11/03/2023 07:32:05
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
		int x,y,k;
		cin >> x >> y >> k;
		//chest is greater than the key
		//get key and then go to chest
		if (x >= y){
			cout << x << '\n';
		}
		//key  is greater than chest
		else {
			x = min(x+k, y);
			cout << y + (y - x) << '\n';
		}
	}
	return 0;
}
