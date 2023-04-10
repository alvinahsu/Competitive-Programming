/*
*  File: CF865A
*  Author: Alvin Hsu
*  Date: 09/04/2023 21:13:12
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
		cout << 2 << '\n';
		cout << a-1 << " " << 1 << '\n';
		cout << a << " " << b << '\n';
	}
	return 0;	
}
