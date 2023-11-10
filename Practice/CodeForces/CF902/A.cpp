/*
*  File: CF902A
*  Author: Alvin Hsu
*  Date: 11/09/2023 20:49:00
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
		int sum = 0;
		for (int i = 0; i < n-1; i++){
			int x;
			cin >> x;
			sum += x;
		}
		cout << -sum << '\n';
	}
	return 0;
}
