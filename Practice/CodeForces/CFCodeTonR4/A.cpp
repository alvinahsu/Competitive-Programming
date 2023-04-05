/*
*  File: CFCodeTonR4A
*  Author: Alvin Hsu
*  Date: 05/04/2023 16:48:24
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
		bool ok = false;
		for (int i = 0;i < n; i++){
			int a;
			cin >> a;
			if (i >= (a - 1)) ok = true;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;	
}
