/*
*  File: CF867A
*  Author: Alvin Hsu
*  Date: 04/24/2023 07:33:46
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
	int q;
	cin >> q;
	while(q--){
		int n,t;
		cin >> n >> t;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		int ans = -1, mx = -1;
		for (int i = 0; i < n; i++){
			if (a[i]+i <= t){
				if (b[i] > mx){
					mx = b[i];
					ans = i+1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
