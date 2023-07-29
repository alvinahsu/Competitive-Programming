/*
*  File: CF889B
*  Author: Alvin Hsu
*  Date: 07/29/2023 09:42:17
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		int ans = 1, curr = 0;
		for (int i = 1; i <= 1e4; i++){
			if (n%i == 0) curr++;
			else {
				curr = 0;
			}
			ans = max(ans, curr);
		}
		cout << ans << '\n';
		
	}
	return 0;
}
