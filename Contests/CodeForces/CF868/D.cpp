/*
*  File: CF868D
*  Author: Alvin Hsu
*  Date: 04/27/2023 07:17:17
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
		vector<int> x(k), c(k);
		string ans = "abc";
		bool ok = true;
		for (int i = 0; i < k; i++){
			cin >> x[i];
		}
		for (int i = 0; i < k; i++){
			cin >> c[i];
		}
		int curr = 3, j = 3, last = 0;
		for (int i = 0; i < k; i++){
			if (c[i] > x[i] || (i && x[i] - x[i-1] < c[i] - c[i-1])) {
				ok = false;
				break;
			}
			while(curr < c[i]) {
				ans += (char)(j + 'a');
				curr++;
			}
			while(ans.size() < x[i]) {
				ans += (char)(last + 'a');
				(last += 1) %= 3;
			}
			j++;
		}
		if (ok){
			cout << "YES\n" << ans << '\n';
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
