/*
*  File: CFEDU148B
*  Author: Alvin Hsu
*  Date: 05/12/2023 07:33:53
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
		vector<int>v(n);
		vector<long long> pref(n+1);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++){
			pref[i+1] = pref[i] + v[i];
		}
		long long mx = 0;
		for (int i = 0; i <= k; i++){
			int start = 2 * (k - i);
			assert(start < n - i);
			long long sum = pref[n-i] - pref[start];
			mx = max(sum, mx);
		}
		cout << mx << '\n';
	}
	return 0;
}
