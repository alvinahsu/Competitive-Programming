/*
*  File: CF887B
*  Author: Alvin Hsu
*  Date: 07/23/2023 10:22:36
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
		int ans = 0;
		for (int i = 0; i <= n; i++){
			int first = i, second = n - i, curr = n, len = 3;
			if (first > second) break;
			while(first+second == curr && second >= first && len < k){
				len++;
				curr = second;
				int diff = second - first;
				second = first;
				first = diff;
			}
			if (first > second) len--;
			ans += (len == k);
		}
		cout << ans << '\n';
	}
	return 0;
}
