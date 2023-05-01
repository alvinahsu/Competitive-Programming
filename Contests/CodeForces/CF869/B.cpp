/*
*  File: CF869B
*  Author: Alvin Hsu
*  Date: 04/29/2023 07:30:07
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
		if (n&1){
			cout << (n == 1 ? 1 : -1) << '\n';
			continue;
		}
		for (int i = 2; i <= n; i+=2){
			cout << i << " " << i-1 << " ";
		}
		cout << '\n';
		
	}
	return 0;
}
