/*
*  File: CF873A
*  Author: Alvin Hsu
*  Date: 05/14/2023 07:33:14
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
		for (int i = 1; i <= n; i++){
			cout << 2*i << " ";
		}
		cout << '\n';
	}
	return 0;
}
