	/*
	*  File: CF872C
	*  Author: Alvin Hsu
	*  Date: 05/08/2023 05:01:11
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
			int n,m;
			cin >> n >> m;
			vector<int>v(n);
			int l = 0, r = 0;
			set<int> pos;
			for (auto &x : v){
				cin >> x;
				if (x == -2) r++;
				else if (x == -1) l++;
				else {
					pos.insert(x);
				}
			}
			int ans = min(m, max(l,r) + (int)pos.size());
			int i = 0, j = pos.size()-i-1;
			for (auto &x : pos){
				int dl = x - 1;
				int dr = m - x;
				assert(dl + dr + 1 == m);
				int pl = min(dl, l + i);
				int pr = min(dr, r + j);
				
				ans = min(m,max(ans, pl + pr + 1));
				i++;
				j--;
			}
			cout << ans << '\n';
		}
		return 0;
	}
