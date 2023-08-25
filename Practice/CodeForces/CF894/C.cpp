/*
*  File: CF894C
*  Author: Alvin Hsu
*  Date: 08/24/2023 13:32:25
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
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool ok = true;
		for (int i = 0; i < n; i++){
			int h = i+1, w = a[i]-1;
			if (w >= n){
				ok = false;
				continue;
			}
			int l = i;
			while(i+1 < n && a[i] == a[i+1]){
				h++;
				i++;
			}
			ok &= (a[w] == h);
		}
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
	return 0;
}
