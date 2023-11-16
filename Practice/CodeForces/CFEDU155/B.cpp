/*
*  File: CFEDU155B
*  Author: Alvin Hsu
*  Date: 11/14/2023 20:33:57
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
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		multiset<long long> ma(a.begin(), a.end());
		multiset<long long> mb(b.begin(), b.end());
		long long ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++){
			long long best = b[i] + *ma.begin();
			ans1 += b[i] + *ma.begin();
			ans2 += a[i] + *mb.begin();
		}
		cout << min(ans1,ans2) << '\n';
		
	}
	return 0;
}
