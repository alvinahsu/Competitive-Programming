/*
*  File: GORAB
*  Author: Alvin Hsu
*  Date: 15/04/2023 21:08:25
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
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++){
		int m,r,n;
		cin >> m >> r >> n;
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		int last = 0, pos = -1, ans = 0;
		bool ok = true, end = false;
		vector<int> used(n);
		for (int i = 0; i < n; i++){
			if (v[i] - r <= last) {
				continue;
			}
			if (!i || (i && used[i-1])) {
				ok = false;
				break;
			}
			assert(v[i-1]-r <= last);
			last = v[i-1]+r;
			used[i-1] = 1;
			end |= (last >= m);
			ans++;
			if (v[i]-r > last) {
				ok = false;
				break;
			}
		}
		if (!end && ok){
			ans++;
			assert(v.back() - r <= last);
			end = v.back() + r >= m;
		}
		cout << "Case #" << t << ": ";
		if (ok && end){
			cout << ans << '\n';
		}
		else {
			cout << "IMPOSSIBLE" << '\n';
		}
	}
	return 0;
}
