/*
*  File: CF863C
*  Author: Alvin Hsu 
*  Date: 04/04/2023 18:36:29
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
		vector<int>v(n-1);
		for (auto &a : v){
			cin >> a;
		}
		vector<int>ans(n);
		ans[0] = v[0];
		for (int i = 1; i < n; i++){
			int curr = v[i-1];
			if (ans[i-1] >= curr){
				ans[i] = i < n-1 && v[i] < curr ? v[i] : curr;
			}
			else {
				ans[i] = curr;
			}
		}
		for (int i = 0; i < n; i++){
			cout << ans[i] << " \n"[i == n-1];
		}
	}
	return 0;	
}
