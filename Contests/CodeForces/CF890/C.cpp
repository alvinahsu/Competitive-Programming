/*
*  File: CF890C
*  Author: Alvin Hsu
*  Date: 08/05/2023 10:10:43
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
	#define int long long
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			int l = a[i], r = 1e9;
			while(l < r){
				int m = l + (r - l + 1) / 2;
				int kk = k;
				//try to make this number m
				//initial difference
				kk -= (m - a[i]);
				//we need the next number to be at least m - 1
				int last = m - 1;
				bool ok = false;
				for (int j = i+1; j < n; j++){
					//satisfies the condition
					if (a[j] >= last) {
						ok = true;
						break;
					}
					//last > a[j], does not satisfy condition
					//need to bring a[j] up to last
					kk -= (last - a[j]);
					//only need one less than previous last
					last--;
				}
				if (ok && kk >= 0){
					l = m;
				}
				else {
					r = m-1;
				}		
			}
			ans = max(ans, l);
		}		
		cout << ans << '\n';
	}
	return 0;
}
