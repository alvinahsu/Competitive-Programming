/*
*  File: CF868A
*  Author: Alvin Hsu
*  Date: 04/27/2023 07:17:17
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
		bool cont = false;
		for (int i = 0; i <= n; i++){
			int pos = i;
			int neg = n - i;
			assert(pos + neg == n);
			if ((pos * (pos-1) / 2) + (neg * (neg-1) / 2) == k){
				cout << "YES" << '\n';
				for (int j = 0; j < pos; j++){
					cout << 1 << " ";
				}
				for (int j = 0; j < neg; j++){
					cout << -1 << " ";
				}
				cout << '\n';
				cont = true;
				break;
			}
		}
		if (cont) continue;
		cout << "NO" << '\n';
	}
	return 0;
}
