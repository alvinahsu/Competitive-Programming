/*
*  File: CF889D
*  Author: Alvin Hsu
*  Date: 07/29/2023 09:42:17
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int N = 2e5+5;
bitset<N> dp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &a : v){
		cin >> a;
	}
	long long ans = 0, sum = 0;
	dp[1] = 1;
	for (int i = 0; i < n; i++){
		dp[i] = 0;
		sum += v[i];
		if (dp[i+1]) ans = max(ans, sum - i);
		dp |= dp << v[i];
	}
	for (int i = n; i <= 2 * n; i++){
		if (dp[i]){
			ans = max(ans, sum - i + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}
