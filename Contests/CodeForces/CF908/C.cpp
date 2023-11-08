/*
*  File: CF908C
*  Author: Alvin Hsu
*  Date: 11/07/2023 06:28:00
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
		int n,k;
		cin >> n >> k;
		vector<int> b(n);
		for (int i = 0; i < n; i++){
			cin >> b[i];	
		}
		bool ok = true;
		int last = n-1;
		for (int i = 0; i < min(n, k); i++){
			if (b[last] > n){
				ok = false;
				break;
			}
			(last += (n - b[last])) %= n;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
