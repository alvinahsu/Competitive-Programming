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
	dp[1] = 1;
	for (int i = 0; i < n; i++){
		dp |= (dp >> (i+1) << (i + 1 + v[i]));
	}
	long long ans = 0, sum = 0;
	for (int i = 1; i < N; i++){
		if (i - 1 < n){
			sum += v[i-1];
		}
		if (dp[i]){
			ans = max(ans, sum - i + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}
