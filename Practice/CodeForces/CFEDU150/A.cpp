/*
*  File: CFEDU150A
*  Author: Alvin Hsu
*  Date: 06/12/2023 13:25:09
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
		if (n > 4){
			cout << "Alice" << '\n';
		}
		else {
			cout << "Bob" << '\n';
		}
	}
	return 0;
}
