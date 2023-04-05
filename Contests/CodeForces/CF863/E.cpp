/*
*  File: CF863E
*  Author: Alvin Hsu
*  Date: 04/04/2023 23:37:54
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

long long dp[19][2];
long long getIndex(string num, int index, bool tight){
	if (index == 0){
		return 1;
	}
	
	int up = tight ? num[num.size()-index]-'0' : 9;
	if (dp[index][tight] != -1){
		return dp[index][tight];
	}
	long long ans = 0;
	for (int i = 0; i <= up; i++){
		if (i == 4) continue;
		long long add = getIndex(num, index-1, tight&(i == up));
		ans += add;
	}
	return dp[index][tight] = ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long k;
		cin >> k;
		long long l = 1, r = 1e13;
		long long res = 0;
		while(l <= r){
			long long mid = l + (r - l) / 2;
			string midS = to_string(mid);
			memset(dp, -1, sizeof dp);

			long long idx = getIndex(midS, midS.size(), 1)-1;
			if (idx >= k) {
				r = mid-1;
				res = mid;
			}
			else {
				l = mid+1;
			}
		}
		cout << res << '\n';
	}
	return 0;	
}
