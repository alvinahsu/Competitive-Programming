/*
*  File: CF825C1
*  Author: Alvin Hsu
*  Date: 06/04/2023 16:11:26
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
		long long ans = 0;
		int l = 0;
		for (int i = 0; i < n; i++){
			int a;
			cin >> a;
			int size = i - l + 1;
			if (a >= size){
				ans += (size);
			}
			else {
				assert(i-a+1 >= 0);
				l = i - a + 1;
				size = i - l + 1;
				ans += (size);
			}
		}
		cout << ans << '\n';
	}
	return 0;	
}
