/*
*  File: CF890B
*  Author: Alvin Hsu
*  Date: 08/05/2023 10:10:43
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
		vector<int> v(n);
		for (auto &a : v){
			cin >> a;
		}
		int cnt1 = count(v.begin(), v.end(), 1);
		long long s = accumulate(v.begin(), v.end(), 0ll);
		long long lb = cnt1 * 2 + (n - cnt1);
		cout << (n > 1 && lb <= s ?  "YES" : "NO") << '\n';
	}
	return 0;
}
