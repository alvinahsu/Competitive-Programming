/*
*  File: CFCodeTonR4D
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
		int q;
		cin >> q;
		long long h = -1;
		long long L = 0, R = 1e18;
		while(q--){
			int type;
			cin >> type;
			if (type == 1){
				int a,b,n;
				cin >> a >> b >> n;
				long long limR = 1ll * (a - b) * (n-1) + a;
				long long limL = n == 1 ? 1 : 1ll * (a - b) * (n-2) + a + 1;
				long long l = max(L, limL);
				long long r = min(R, limR);
				if (l <= r){
					L = l;
					R = r;
					cout << 1 << " ";
				}
				else {
					cout << 0 << " ";
				}
			}
			else {
				int a,b;
				cin >> a >> b;
				long long h1 = max(1ll,(L - b - 1) / (a - b) + 1);
				long long h2 = max(1ll,(R - b - 1) / (a - b) + 1);
				cout << (h1 == h2 ? h1 : -1) << " ";
			}
		}
		cout << '\n';
	}
	return 0;	
}
