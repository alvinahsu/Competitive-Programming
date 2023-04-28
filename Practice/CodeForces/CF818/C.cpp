/*
*  File: CF818C
*  Author: Alvin Hsu
*  Date: 04/28/2023 08:06:22
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
		vector<int>a(n), b(n);
		for (auto &x : a){
			cin >> x;
		}
		for (auto &x : b){
			cin >> x;
		}
		if (a == b){
			cout << "YES" << '\n';
			continue;
		}
		bool ok = true;
		for (int i = 0; i < n; i++){
			ok &= a[i] <= b[i];
			if (a[i] < b[i]){
				ok &= b[(i+1)%n]+1 >= b[i];
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
	return 0;
}
