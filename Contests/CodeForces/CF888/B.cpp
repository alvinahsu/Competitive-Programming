/*
*  File: CF888B
*  Author: Alvin Hsu
*  Date: 07/25/2023 10:28:24
*/

#include <algorithm>
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
		vector<int> v(n);
		vector<int> odd, even, type(n);
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			type[i] = x&1;
			if (x&1){
				odd.push_back(x);
			}
			else {
				even.push_back(x);
			}
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		int j = 0, k = 0;
		for (int i = 0; i < n; i++){
			if (type[i]){
				v[i] = odd[j++];
			}
			else {
				v[i] = even[k++];
			}
		}
		bool ok = is_sorted(v.begin(), v.end());
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
