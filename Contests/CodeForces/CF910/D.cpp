/*
*  File: CF910D
*  Author: Alvin Hsu
*  Date: 11/19/2023 06:28:26
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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int mx = 0;
		long long curr = 0;
		for (int i = 0; i < n; i++){
			cin >> b[i];
			if (b[i] < a[i]) swap(a[i], b[i]);
			curr += (b[i] - a[i]);
			
			if (a[i] > a[mx]) mx = i;
			else if (a[i] == a[mx] && b[i] > b[mx]) mx = i;
		}
		long long ans = curr;
		
		for (int i = 0; i < n; i++){
			long long check = curr-(b[i]-a[i])-(b[mx]-a[mx]);
			check += (b[mx]-a[i]) + (a[mx]-b[i]);
			ans = max(ans, check);
		}
		cout << ans << '\n';
		
	}
	return 0;
}
