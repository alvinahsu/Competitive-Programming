/*
*  File: CF874B
*  Author: Alvin Hsu
*  Date: 05/19/2023 07:31:18
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
		vector<pair<int,int>>a(n),b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i].first;
			a[i].second = i;
		}
		for (int i = 0; i < n; i++){
			cin >> b[i].first;
			b[i].second = i;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<int> ans(n);
		for (int i = 0; i < n; i++){
			ans[a[i].second] = b[i].first;
		}
		for (int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << '\n';
		
	}
	return 0;
}
