/*
*  File: CF878C
*  Author: Alvin Hsu
*  Date: 06/11/2023 10:24:26
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
		int n,k,q;
		cin >> n >> k >> q;
		vector<int> a(n);
		for (auto &x : a){
			cin >> x;
		}
		vector<int> seg;
		int i = 0, l = 0;
		for (; i < n; i++){
			if (a[i] > q){
				if (i - l >= k){
					seg.push_back(i - l);
				}
				l = i+1;
			}
		}
		if (i - l >= k) seg.push_back(i - l);
		long long ans = 0;
		for (auto s : seg){
			assert(s >= k);
			int sum = s - k + 1;
			ans += (1ll * sum * (sum+1)) / 2;
		}
		cout << ans << '\n';
		
	}
	return 0;
}
