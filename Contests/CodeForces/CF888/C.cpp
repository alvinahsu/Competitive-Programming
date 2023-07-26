/*
*  File: CF888C
*  Author: Alvin Hsu
*  Date: 07/25/2023 10:28:24
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
		vector<int> v(n);
		for (auto &a : v){
			cin >> a;
		}
		bool first = false, second = false;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++){
			if (!first){
				cnt1 += (v[i] == v[0]);
				if (cnt1 >= k){
					first = true;
				}
			}
			else{
				cnt2 += (v[i] == v[n-1]);
				if (cnt2 >= k){
					second = true;
				}
			}
		}
		bool ok = first && second;
		if (v[0] == v[n-1]){
			ok |= cnt1 >= k;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
