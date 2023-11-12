/*
*  File: CF901A
*  Author: Alvin Hsu
*  Date: 11/11/2023 15:53:38
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
		int a,b,n;
		cin >> a >> b >> n;
		vector<int> v(n);
		long long ans = b;
		for (auto &it : v){
			cin >> it;
			if (it >= a){
				ans += a-1;
			}
			else {
				ans += it;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}