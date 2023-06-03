/*
*  File: CF876C
*  Author: Alvin Hsu
*  Date: 06/03/2023 10:12:28
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
		vector<int>a(n);
		for (auto &x : a){
			cin >> x;
		}
		if (a[n-1] == 1){
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		int place = 0;
		for (int i = n-1; i >= 0;){
			if (a[i]){
				int cnt = 0;
				while(i >= 0 && a[i]){
					cnt++;
					i--;
				}
				cnt--;
				for (int j = 0; j < cnt; j++){
					if (place+1 < n) {
						place++;
						cout << 0 << ' ';
					}
				}
				assert(place <= n);
				cout << cnt+1 << ' ';
			}
			else {
				assert(place <= n);
				place++;
				cout << 0 << ' ';
				i--;
			}
		}
		cout << '\n';
	}
	return 0;
}
