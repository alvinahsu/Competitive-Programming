/*
*  File: UCSDSP23_2B
*  Author: Alvin Hsu
*  Date: 04/24/2023 18:01:48
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
	int n;
	cin >> n;
	vector<int> odd, even;
	while(n--){
		int a;
		cin >> a;
		if (a&1) odd.push_back(a);
		else even.push_back(a);
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	int ans = -1;
	if (odd.size() >= 2){
		int sz = odd.size();
		ans = max(ans, odd[sz-1] + odd[sz-2]);
	}
	if (even.size() >= 2){
		int sz = even.size();
		ans = max(ans, even[sz-1] + even[sz-2]);
	}
	cout << ans << '\n';
	return 0;
}
