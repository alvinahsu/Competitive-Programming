/*
*  File: CF892C
*  Author: Alvin Hsu
*  Date: 08/14/2023 16:36:22
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
		long long ans = n * (n+1) * (2*n+1) / 6 - n*n;
		for (int i = n; i >= 1; i--){
			//reverse [i:n]
			long long curr = (i-1) * (i) * (2*(i-1)+1) / 6, mx = 0;
			for (int j = i; j <= n; j++){
				mx = max(mx, 1ll*j*(n-j+i));
				curr += (1ll*j*(n-j+i));
			}
			curr -= max(1ll*i*i,mx);
			assert(curr >= 0);
			ans = max(ans, curr);
		}
		cout << ans << '\n';
	}
	return 0;
}
